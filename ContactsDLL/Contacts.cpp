#include "pch.h"
#include "Contacts.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

static void toLowercase(std::string& s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::tolower(c); });
}

static void freeContact(const contacts::Contact* c) {
	free(c->name);
	free(c->phone);
	free(c->email);

	delete c;
}

template<typename T>
static T** copyVectorPointerToArray(std::vector<T*>* vec, size_t* size) {
	*size = vec->size();
	T** array = new T * [*size];
	std::copy(vec->begin(), vec->end(), array);

	return array;
}

static bool initialized = false;
static std::vector<contacts::Contact*>* contactList;
static std::map<int, int>* contactIndexById;
static int nextId = 0;

namespace contacts
{

	const char* FILENAME = "contacts.csv";

	void initialize() {
		if(initialized)
			return;

		initialized = true;
		contactList = new std::vector<Contact*>();
		contactIndexById = new std::map<int, int>();
		nextId = 0;

		std::ifstream file(FILENAME);
		if (!file.is_open()) // No file yet, will create on first add
			return;

		std::string line;

		while (std::getline(file, line))
		{
			if (line.empty())
				continue;

			size_t pos = 0, nextPos;
			Contact* contact = new Contact;

			// Assuming the format is: id,name,phone,email
			contact->id = std::stoi(line.substr(pos, line.find(',')));

			pos = line.find(',') + 1;
			nextPos = line.find(',', pos);
			contact->name = _strdup(line.substr(pos, nextPos - pos).c_str());
			
			pos = nextPos + 1;
			nextPos = line.find(',', pos);
			contact->phone = _strdup(line.substr(pos, nextPos - pos).c_str());
			
			pos = nextPos + 1;
			contact->email = _strdup(line.substr(pos).c_str());

			contactList->push_back(contact);

			if(contact->id >= nextId)
				nextId = contact->id + 1;
		}

		file.close();
		sortContactsByName();
	}

	Contact** getContacts(size_t* size) {
		return copyVectorPointerToArray<Contact>(contactList, size);
	}

	Contact* addContact(const Contact& contact)
	{
		std::ofstream file(FILENAME, std::ios::app);
		if (!file.is_open())
			return nullptr;

		int id = nextId++;
		Contact *pContact;

		contactList->push_back(pContact = new Contact(contact));
		// free(contact.name);
		// free(contact.phone);
		// free(contact.email);

		pContact->id = id;

		file << id << "," << pContact->name << "," << pContact->phone << "," << pContact->email << std::endl;

		file.close();
		sortContactsByName();

		return pContact;
	}

	Contact* addContactByFields(const char* name, const char* phone, const char* email)
	{
		return addContact({ -1, _strdup(name), _strdup(phone), _strdup(email) });
	}

	API Contact* updateContact(const Contact& contact)
	{
		if(contactIndexById->count(contact.id) == 0)
			return nullptr;

		std::ofstream file(FILENAME);
		if (!file.is_open())
			return nullptr;

		int index = contactIndexById->at(contact.id);
		Contact *c;

		freeContact(contactList->at(index));
		contactList->at(index) = c = new Contact(contact);
		// free(contact.name);
		// free(contact.phone);
		// free(contact.email);

		for (const auto& c : *contactList) {
			file << c->id << "," << c->name << "," << c->phone << "," << c->email << std::endl;
		}

		file.close();

		return c;
	}

	API Contact* updateContactByFields(int id, const char* name, const char* phone, const char* email)
	{
		return updateContact({ id, _strdup(name), _strdup(phone), _strdup(email) });
	}

	void removeContact(int id)
	{
		std::ofstream file(FILENAME);
		if (!file.is_open())
			return;

		int index = contactIndexById->at(id);

		freeContact(contactList->at(index));
		contactList->erase(contactList->begin() + index);
		contactIndexById->erase(id);

		for (const auto& contact : *contactList)
			file << contact->id << "," << contact->name << "," << contact->phone << "," << contact->email << std::endl;

		file.close();
	}

	void removeContacts(int ids[], size_t size)
	{
		std::ofstream file(FILENAME);
		if (!file.is_open())
			return;

		for (int i = 0; i < size; i++)
		{
			int
				id = ids[i],
				index = contactIndexById->at(id);

			freeContact(contactList->at(index));
			contactList->erase(contactList->begin() + index);
			contactIndexById->erase(id);
		}

		for (const auto& contact : *contactList)
			file << contact->id << "," << contact->name << "," << contact->phone << "," << contact->email << std::endl;

		file.close();
	}

	Contact** filterContactsByName(const char* name, size_t* size)
	{
		if (name == "")
			return copyVectorPointerToArray<Contact>(contactList, size);

		std::string contactName, lowerName = name;
		std::vector<Contact*> filtered;

		toLowercase(lowerName);

		for (const auto& contact : *contactList)
		{
			contactName = contact->name;
			toLowercase(contactName);


			if (contactName.find(lowerName) != std::string::npos)
				filtered.push_back(contact);
		}

		return copyVectorPointerToArray<Contact>(&filtered, size);
	}

	void clear()
	{
		for (const auto& contact : *contactList)
			freeContact(contact);

		delete contactList;
		delete contactIndexById;
		initialized = false;
	}

	void sortContactsByName()
	{
		std::sort(contactList->begin(), contactList->end(), [](const Contact* a, const Contact* b) {
			return std::string(a->name) < std::string(b->name);
			});

		contactIndexById->clear();
		for (int i = 0; i < contactList->size(); i++)
			contactIndexById->emplace(contactList->at(i)->id, i);
	}

} // namespace contacts


