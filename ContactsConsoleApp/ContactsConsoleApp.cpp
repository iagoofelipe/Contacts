#include <iostream>
#include "Contacts.h"

#include <vector>
#include <algorithm>

void displayContact(const contacts::Contact* contact)
{
	if (!contact)
	{
		std::cout << "Contact is null.\n";
		return;
	}

	std::cout
		<< "<Contact id=" << contact->id
		<< " name=" << (contact->name ? contact->name : "N/A")
		<< " phone=" << (contact->phone ? contact->phone : "N/A")
		<< " email=" << (contact->email ? contact->email : "N/A")
		<< ">\n";
}

int main()
{
	contacts::initialize();
	size_t size;

	contacts::Contact** contacts = contacts::getContacts(&size);

	for (int i = 0; i < size; ++i)
		displayContact(contacts[i]);

	if (!size)
		std::cout << "No contacts found.\n";

	std::cout << "\nadding contacts...\n";
	contacts::Contact* added = contacts::addContactByFields("John Doe", "1237890", "jhon@email.com");

	contacts = contacts::getContacts(&size);

	for (int i = 0; i < size; ++i)
		displayContact(contacts[i]);

	std::cout << "\nremoving contacts...\n";
	contacts::removeContact(added->id);

	contacts = contacts::getContacts(&size);
	for (int i = 0; i < size; ++i)
		displayContact(contacts[i]);

	contacts::clear();


	std::vector<std::string> names = { "Eve", "Bob", "David", "Charlie", "Alice" };

	for (const auto& name : names)
		std::cout << name << "\n";

	std::sort(names.begin(), names.end());

	std::cout << "\nSorted names:\n";
	for (const auto& name : names)
		std::cout << name << "\n";
}
