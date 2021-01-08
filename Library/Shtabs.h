
#ifndef _SHTABS_H_
#define _SHTABS_H_

#include <iostream>
#include "Table.h"
#include "Army.h"

namespace Shtabs {
	const char locations[][20] = { "North", "South", "West", "East" };
	/*template <class T>
	int set_person_parameters(std::istream& is, T& obj, int p); */
	class Subdivision {
	private:
		Matrix::Table table;
		int location;
		int type;//shtab ili ne shtab?
	public:
		//constructors
		Subdivision() : table(), location(0), type(0) {}
		Subdivision(Matrix::Table& g_table, int g_location = 0, int g_type = 0);
		//getters
		Matrix::Table get_table() const { return table; }
		int get_location() const { return location; }
		int get_type() const { return type; }
		//setters
		int set_table(Matrix::Table& g_table) { table = g_table; return 0; }
		int set_location(int g_location);
		int set_type(int g_type = 1);
	};
	class Field_commander : public Army::Field_fighter, public Army::Staff_officer {
	private:
		Subdivision* subdivision;
	protected:
		virtual std::ostream& show(std::ostream&, int condition = 0)const;
		virtual std::istream& get(std::istream&, int condition = 0);
		virtual std::istream& edit(std::istream&, int condition = 0);
		virtual int my_rank();
		virtual int my_spec();
		virtual bool am_i_sanitar();
	public:
		~Field_commander();
		Field_commander() : Army::Field_fighter(), Army::Staff_officer() { person = Army::Person(); subdivision = new Subdivision(); }
		virtual Field_commander* clone() const {
			return new Field_commander(*this);
		}
		Subdivision* get_subdivision();
		int set_subdivision_table(Matrix::Table g_table) { subdivision->set_table(g_table); return 0; }
	};
	class Max_commander : public Army::Staff_officer {
	private:
		Subdivision* subdivision;
	protected:
		virtual std::ostream& show(std::ostream&, int condition = 0)const;
		virtual std::istream& get(std::istream&, int condition = 0);
		virtual std::istream& edit(std::istream&, int condition = 0);
		virtual bool am_i_sanitar();
		virtual int my_rank();
		virtual int my_spec();
	public:
		~Max_commander();
		/*template <class T>
		friend int set_person_parameters(std::istream& is, T& obj, int p); */
		Max_commander() : Staff_officer(), subdivision() { person = Army::Person(); }
		virtual Max_commander* clone() const {
			return new Max_commander(*this);
		}
		Subdivision* get_subdivision() { return subdivision; }
		int set_subdivision_table(Matrix::Table g_table) { subdivision->set_table(g_table); return 0; }
	};
	class Infield {
	private:
		Field_commander* commander_1, * commander_2;
		int location;
		int duration;
	public:
		Infield() :location(0), duration(0) { commander_1 = new Field_commander(); commander_2 = new Field_commander(); };
		int get_duration() const { return duration; }
		const char* get_location() const { return locations[location]; }
		int set_duration(int g_duration) { duration = g_duration; return 0; }
		int set_location(int g_location) { if ((g_location > 0) && (g_location < 4)) location = g_location; else throw std::exception("Invalid loc!"); return 0; }
		int get_soldier(int g_key) const;
		int add_soldier(int g_key, int g_status, int team, Army::Soldier*);
		int edit_soldier(int g_key);
		int get_n(int team, int condition = 0, int g_rank = 69, int g_spec = 69) const;
		int delete_soldier(int g_key);
		int swap_soldier(int g_key);
		Matrix::Table get_table(int team) const;
	};
}

#endif