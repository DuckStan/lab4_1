#ifndef _ARMY_H_
#define _ARMY_H_

#include <iostream>

namespace Army{
	const char def[] = "Unknown";
	const char ranks[][20] = { "Officer Cadet", "Second Lieutenant", "Lieutenant", "Captain", "Major", "Lieutenant-Colonel", "Colonel", "Brigadier", "Major-General","Lieutenant-General", "General", "Field-Marshal" };
	const char specs[][20] = { "Pehota", "Specnaz", "Razvedchik", "Sniper", "Saper", "RHBZ", "Sanitar", "Radist" };
	const char hq_posts[][20] = { "military HQ", "army HQ", "corps HQ", "division HQ", "brigade HQ" };
	const char locations[][20] = { "North", "South", "West", "East"};

	template <class T>
	int set_person_parameters(std::istream& is, T& obj, int p);

	struct Instruction {
		char* words = nullptr;
		int reglament;
	};
	int dialog_window(std::istream& is, int class_type);
class Person{
private:
	char* name=nullptr;
	char* surname=nullptr;
	char* patronymic=nullptr;
	int rank;
	int uniform_size;
public:
	//constructor
	Person();
	Person(char* g_name, char* g_surname, char* g_patronymic, int g_rank, int g_uniform_size);
	Person(const Person& p);
	//destructor
	~Person() {
		delete[] name;
		delete[] surname;
		delete[] patronymic;
	}
	//operator overload
	friend std::ostream& operator <<(std::ostream&, const Person&);
	friend std::istream& operator >>(std::istream&, Person&);
	//getters
	char* get_name() const { return name; }
	char* get_surname() const { return surname; }
	char* get_patronymic() const { return patronymic; }
	int get_rank() const { return rank; }
	int get_uniform_size() const { return uniform_size; }
	//setters
	Person& set_name(char* g_name);
	Person& set_surname(char* g_surname);
	Person& set_patronymic(char* g_patronymic);
	Person& set_rank(int g_rank);
	Person& set_uniform_size(int g_uniform_size);
};
class Soldier {
protected:
	virtual std::ostream& show(std::ostream&, int condition = 0)const = 0;
	virtual std::istream& get(std::istream&, int condition = 0) = 0;
public:
	template <class T>
	friend int set_person_parameters(std::istream& is, T& obj, int p);
	virtual std::istream& edit(std::istream&, int condition = 0) = 0;
	virtual bool am_i_sanitar() = 0;
	virtual int my_rank() = 0;
	virtual int my_spec() = 0;
	virtual Soldier* clone()const = 0;
	friend std::ostream& operator <<(std::ostream&, const Soldier&);
	friend std::istream& operator >>(std::istream&, Soldier&);
	virtual ~Soldier() = 0;
};
class Field_fighter : public virtual Soldier{
private:
	Person person;
protected:
	int spec;
	char** orders=nullptr;
	int n_orders=0;
	virtual std::ostream& show(std::ostream&, int condition = 0)const;
	virtual std::istream& get(std::istream&, int condition = 0);
	virtual std::istream& edit(std::istream&, int condition = 0);
	virtual bool am_i_sanitar();
	virtual int my_rank();
	virtual int my_spec();
	void delete_orders(char** some_orders);
	int delete_order(int order_n);
public:
	template <class T>
	friend int set_person_parameters(std::istream& is, T& obj, int p);
	//constructors
	Field_fighter(): person(), spec(0), n_orders(0){}
	Field_fighter(char* g_name, char* g_surname, char* g_patronymic, int g_rank, int g_uniform_size, int spec=0, char *order=nullptr);
	Field_fighter(const Person& p, int g_spec = 0, char* order = nullptr);
	virtual Soldier* clone() const {
		return new Field_fighter(*this);
	}
	//destructor
	~Field_fighter();
	//getters
	const char* get_spec() const { return specs[spec]; }
	char* get_recent_order() const{ if (n_orders > 0) return orders[0]; else return nullptr; }
	char* get_last_order() const{ if (n_orders > 0) return orders[n_orders - 1]; else return nullptr; }
	//setters
	Field_fighter& add_order(char* g_order = nullptr);
	Field_fighter& set_spec(int g_spec = 0);
};
class Staff_officer: public virtual Soldier {
private:
	Person person;
protected:
	int hq_post;
	int n_instructions;
	Instruction *instructions=nullptr;
	virtual std::ostream& show(std::ostream&, int condition = 0)const;
	virtual std::istream& get(std::istream&, int condition = 0);
	virtual std::istream& edit(std::istream&, int condition = 0);
	virtual bool am_i_sanitar();
	virtual int my_rank();
	virtual int my_spec();
	void delete_instructions(Instruction* some_instr);
	int delete_instr(int instr_reg);
public:
	template <class T>
	friend int set_person_parameters(std::istream& is, T& obj, int p);
	//constructors
	Staff_officer() : person(), hq_post(0), n_instructions(0) {}
	Staff_officer(char* g_name, char* g_surname, char* g_patronymic, int g_rank, int g_uniform_size, int g_hq_post = 1, char* g_words = nullptr, int g_reg = 0);
	Staff_officer(const Person& p, int g_hq_post = 1, char* g_words = nullptr, int g_reg = 0);
	virtual Staff_officer* clone() const {
		return new Staff_officer(*this);
	}
	//destructor
	~Staff_officer();
	//getters
	const char* get_post() const { return hq_posts[hq_post]; }
	char* get_recent_instruction() const{ if (n_instructions > 0) return instructions[0].words; else return nullptr; }
	char* get_last_instruction() const{ if (n_instructions > 0) return instructions[n_instructions - 1].words; else return nullptr; }
	//setters
	Staff_officer& add_instruction(int g_reg, char* g_words);
	Staff_officer& set_post(int g_post = 0);
};

}

#endif