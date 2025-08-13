#pragma once

#ifdef CONTACTSDLL_EXPORTS
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

namespace contacts
{
	struct API Contact
	{
		int id = -1;
		char* name = nullptr;
		char* phone = nullptr;
		char* email = nullptr;
	};

	extern "C" API void initialize();
	extern "C" API Contact** getContacts(size_t* size);
	extern "C" API Contact* addContact(const Contact& contact);
	extern "C" API Contact* addContactByFields(const char* name, const char* phone, const char* email);
	extern "C" API void removeContact(int id);
	extern "C" API Contact** filterContactsByName(const char* name, size_t* size);
	extern "C" API void clear();
	extern "C" API void sortContactsByName();

} // namespace contacts


