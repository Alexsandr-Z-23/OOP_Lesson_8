#include <iostream>
#include<string>
using namespace std;

class Person
{
	string name;
	unsigned age;
	string company;
public:
	Person(string p_name, unsigned p_age, string p_company)
	{
		name = p_name;
		age = p_age;
		company = p_company;
	}
	string getName() const { return name; }
	int getAge() const { return age; }
	string getCom() const { return company; }
	
	string operator [](const string& indexName)const
	{
		if (indexName == "name")return name;
		else if (indexName == "age") return to_string(age);
		else if (indexName == "company") return company;
		else return "Not IndexName";

	}
string operator [](unsigned index)const
	{
		switch (index)
		{
		case 0:return name;
		case 1:return to_string(age);
		case 2:return company;
		default:
			return "NOT INDEX";
		}

	}


friend std::ostream& operator << (std::ostream& stream, const Person& obj)
	{
		stream << "Person: \n";
		stream << "\t Name    \t :\t" << obj.getName() << endl;
		stream << "\t Age     \t :\t" << obj.getAge() << endl;
		stream << "\t Company \t :\t" << obj.getCom() << endl;
		return stream;
	}

};


int main()
{
	Person Tom{ "Tom",26,"Microsoft" };
	//cout << Tom;
	cout << Tom["name"] << "\n" << Tom["age"] << "\n" << Tom["company"] << endl;
}


