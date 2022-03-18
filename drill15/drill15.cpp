#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
public:
	Person(){}
	Person(string f,string l, int a) : name1(f),name2(l), age(a)
	{
      if(a < 0 || a >= 150 )
      {
				throw runtime_error ("Invalid age.");
	  }
	  char t[14] = {';', ':', '\"', '\'', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!'};
	  string n = f + l;
	  for (int i = 0; i < n.length(); i++)
	  {
		//; : " ' [ ] * & ^ % $ # @ !
		for (int j = 0; j < (sizeof(t)/sizeof(t[0])); j++)
		{
			if (n[i] == t[j])
			{
			  throw runtime_error ("Invalid name.");
			}
		}
	  }
	}

	string n1() const 
	{
		return name1;
	}
	string n2() const 
	{
		return name2;
	}
	int a() const 
	{
		return age;
	}

private:
	string name1;
	string name2;
	int age;
};

ostream& operator<<(ostream& os, const Person& p)
 { 
  return os<<p.n1()<<" "<<p.n2()<<" "<<p.a();
 } 

istream& operator>>(istream& is, Person& p)
{
	string n1;
	string n2;
	int a;
	is >> n1 >> n2 >>a;
	
	p = Person(n1, n2, a);
	return is;
}

int main()
{

Person p = Person("Goofy", " " ,63);
/*p.name = "Goofy";
p.age = 63;*/
//cout << <<"\n";
vector<Person> elemek;
for(Person p; cin >> p;)//while(cin>>p); //foreach addig olvas amíg nincs break
    { 
		if(p.n1() == "end") break;
		elemek.push_back(p);
	}
	for(Person p: elemek)//c# foreach(Person p in elemek) a p vegye fel az elemek minden egyes elemét
	{
		cout << p << "\n";
	}	


return 0;
}