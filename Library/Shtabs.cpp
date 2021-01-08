#include "Shtabs.h"
#include <iostream>

namespace Shtabs {
	std::ostream& Field_commander::show(std::ostream& os, int condition)const
	{
		if (condition == 0) {
			os << "Field commander: " << person;
		}
		Field_fighter::show(os, 1);
		Staff_officer::show(os, 1);

		return os << std::endl;
	}
	std::istream& Field_commander::get(std::istream& is, int condition)
	{
		if (condition == 0) {
			try {
				is >> person;
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
				throw std::exception("Personal info couldnt be gathered!");
			}
		}

		try {
			Field_fighter::get(is, 1);
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
			throw std::exception("Orders couldnt be gathered!");
		}
		try {
			Staff_officer::get(is, 1);
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
			throw std::exception("Instructions couldnt be gathered!");
		}

		return is;
	}
	std::istream& Field_commander::edit(std::istream& is, int condition) {
		while (1) {
			int k = 0;
			k = Army::dialog_window(is, 3);
			switch (k) {
			case 0: return is;
			case 1:
				try {
					person.set_person_parameters(is, 1);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			case 2:
				try {
					person.set_person_parameters(is, 2);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			case 3:
				try {
					person.set_person_parameters(is, 3);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			case 4:
				try {
					person.set_person_parameters(is, 4);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			case 5:
				try {
					person.set_person_parameters(is, 5);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			case 6:
				int g_spec;
				std::cout << "List of specialties:" << std::endl;
				for (int i = 0; i < 8; i++) {
					std::cout << i << ". " << Army::specs[i] << std::endl;
				}
				std::cout << "Choose one of them:";
				is >> g_spec;
				try {
					set_spec(g_spec);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			case 7:
				while (1) {
					int action = 0;
					std::cout << "0. Done here" << std::endl;
					std::cout << "1. Add order" << std::endl;
					std::cout << "2. Delete order" << std::endl;
					std::cout << "Do what you want: ";
					is >> action;
					switch (action) {
					case 0:
						break;
					case 1:
						std::cout << "Input order: ";
						char temp[20];
						is >> temp;
						if (is.good()) {
							try {
								add_order(temp);
							}
							catch (std::exception& ex) {
								std::cout << ex.what() << std::endl;
							}
						}
						else {
							throw std::exception("Something bad happened to the stream!");
						}
					case 2:
						int order_n;
						std::cout << "Which order?";
						is >> order_n;
						if (is.good()) {
							try {
								delete_order(order_n);
							}
							catch (std::exception& ex) {
								std::cout << ex.what() << std::endl;
							}
						}
						else {
							std::cout << "Something bad happened to the stream!" << std::endl;
						}
					default:
						std::cout << "What the hell, you didnt choose anything good!" << std::endl;
					}
				}
			case 8:
				int g_post;
				std::cout << "List of hq posts:" << std::endl;
				for (int i = 0; i < 5; i++) {
					std::cout << i << ". " << Army::hq_posts[i] << std::endl;
				}
				std::cout << "Choose one of them:";
				is >> g_post;
				try {
					set_post(g_post);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			case 9:
				while (1) {
					int g_reg = 0;
					int action = 0;
					std::cout << "0. Done here" << std::endl;
					std::cout << "1. Add instruction" << std::endl;
					std::cout << "2. Delete instruction" << std::endl;
					std::cout << "Do what you want: ";
					is >> action;
					switch (action) {
					case 0:
						break;
					case 1:
						std::cout << "Input instruction and reglament: ";
						char temp[20];
						is >> temp >> g_reg;
						if (is.good()) {
							try {
								add_instruction(g_reg, temp);
							}
							catch (std::exception& ex) {
								std::cout << ex.what() << std::endl;
							}
						}
						else {
							throw std::exception("Something bad happened to the stream!");
						}
					case 2:
						int order_n;
						std::cout << "Which instruction?";
						is >> order_n;
						if (is.good()) {
							try {
								delete_instr(order_n);
							}
							catch (std::exception& ex) {
								std::cout << ex.what() << std::endl;
							}
						}
						else {
							std::cout << "Something bad happened to the stream!" << std::endl;
						}
					default:
						std::cout << "What the hell, you didnt choose anything good!" << std::endl;
					}
				}
			default:
				std::cout << "You have inputted some strange stuff man!" << std::endl;
			}
		}
		return is;
	}
	Subdivision* Field_commander::get_subdivision() {
		return subdivision;
	}
	std::ostream& Max_commander::show(std::ostream& os, int condition)const {
		if (condition == 0) {
			os << "Max commander: " << person;
		}
		Staff_officer::show(os, 1);
		return os << std::endl;
	}

	std::istream& Max_commander::get(std::istream& is, int condition)
	{
		if (condition == 0) {
			try {
				is >> person;
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
				throw std::exception("Personal info couldnt be gathered!");
			}
		}
		try {
			Staff_officer::get(is, 1);
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
			throw std::exception("Instructions couldnt be gathered!");
		}
		return is;
	} 
	std::istream& Max_commander::edit(std::istream& is, int condition) {
		Staff_officer::edit(is);
		return is;
	}
	bool Field_commander::am_i_sanitar() {
		if (spec == 6) return true;
		else return false;
	}
	bool Max_commander::am_i_sanitar() {
		return false;
	}
	int Field_commander::my_rank() {
		return person.get_rank();
	}
	int Field_commander::my_spec() {
		return spec;
	}
	int Max_commander::my_rank() {
		return person.get_rank();
	}
	int Max_commander::my_spec() {
		return 69;
	}
	int Subdivision::set_location(int g_location) {
		if (type == 0) throw std::exception("This subdivision is HQ, cannot change location!");
		if (type == 1) {
			if ((g_location >= 0) && (g_location <= 4)) location = g_location;
			else throw std::exception("Invalid location!");
		}
		return 0;
	}
	int Subdivision::set_type(int g_type) {
		if ((g_type == 0) || (g_type == 1)) { type = g_type; return 0; }
		else throw std::exception("Invalid subdivision type!");
		return 0;
	}
	Subdivision::Subdivision(Matrix::Table& g_table, int g_location, int g_type) :table(g_table) {
		try {
			set_location(g_location);
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
		try {
			set_type(g_type);
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	int Infield::get_soldier(int g_key) const {
		Subdivision* sub_1 = nullptr, * sub_2 = nullptr;
		sub_1 = commander_1->get_subdivision();
		sub_2 = commander_2->get_subdivision();
		Matrix::Table table_1, table_2;
		table_1 = sub_1->get_table();
		table_2 = sub_2->get_table();

		Matrix::ConstTableIt p_1, p_2;
		bool in_1 = true, in_2 = true;
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_1 = false;
		}
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_2 = false;
		}

		if ((!in_1) && (!in_2)) {
			std::cout << "No such soldier!" << std::endl;
			return 0;
		}
		if (in_1) {
			std::cout << p_1->info << std::endl;
		}
		if (in_2) {
			std::cout << p_2->info << std::endl;
		}
		return 0;
	}
	int Infield::edit_soldier(int g_key) {
		Subdivision* sub_1 = nullptr, * sub_2 = nullptr;
		sub_1 = commander_1->get_subdivision();
		sub_2 = commander_2->get_subdivision();
		Matrix::Table table_1, table_2;
		table_1 = sub_1->get_table();
		table_2 = sub_2->get_table();

		Matrix::ConstTableIt p_1, p_2;
		bool in_1 = true, in_2 = true;
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_1 = false;
		}
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_2 = false;
		}

		if ((!in_1) && (!in_2)) {
			std::cout << "No such soldier!" << std::endl;
			return 0;
		}
		if (in_1) {
			p_1->info->edit(std::cin);
		}
		if (in_2) {
			p_2->info->edit(std::cin);
		}
		return 0;
	}
	int Infield::get_n(int team, int condition, int g_rank, int g_spec) const {
		Subdivision* sub_1 = nullptr, * sub_2 = nullptr;
		sub_1 = commander_1->get_subdivision();
		sub_2 = commander_2->get_subdivision();
		Matrix::Table table_1, table_2;
		table_1 = sub_1->get_table();
		table_2 = sub_2->get_table();

		int count = 0;
		if (team == 1) {
			try {
				count = table_1.get_amount_of_fighters(condition, g_rank, g_spec);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			return count;
		}
		else {
			try {
				count = table_2.get_amount_of_fighters(condition, g_rank, g_spec);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			return count;
		}
		return count;
	}
	int Infield::delete_soldier(int g_key) {
		Subdivision* sub_1 = nullptr, * sub_2 = nullptr;
		sub_1 = commander_1->get_subdivision();
		sub_2 = commander_2->get_subdivision();
		Matrix::Table table_1, table_2;
		table_1 = sub_1->get_table();
		table_2 = sub_2->get_table();

		Matrix::ConstTableIt p_1, p_2;
		bool in_1 = true, in_2 = true;
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_1 = false;
		}
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_2 = false;
		}

		if ((!in_1) && (!in_2)) {
			std::cout << "No such soldier!" << std::endl;
			return 0;
		}
		if (in_1) {
			table_1.remove(g_key);
			commander_1->set_subdivision_table(table_1);
		}
		if (in_2) {
			table_2.remove(g_key);
			commander_1->set_subdivision_table(table_2);
		}
		return 0;
	}
	int Infield::swap_soldier(int g_key) {
		Subdivision* sub_1 = nullptr, * sub_2 = nullptr;
		sub_1 = commander_1->get_subdivision();
		sub_2 = commander_2->get_subdivision();
		Matrix::Table table_1, table_2;
		table_1 = sub_1->get_table();
		table_2 = sub_2->get_table();

		Matrix::ConstTableIt p_1, p_2;
		bool in_1 = true, in_2 = true;
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_1 = false;
		}
		try {
			p_1 = table_1.find(g_key);
		}
		catch (std::exception) {
			in_2 = false;
		}

		if ((!in_1) && (!in_2)) {
			std::cout << "No such soldier!" << std::endl;
			return 0;
		}
		if (in_1) {
			table_2.insert(p_1->key, p_1->status, p_1->info);
			table_1.remove(g_key);
			commander_1->set_subdivision_table(table_1);
			commander_2->set_subdivision_table(table_2);
		}
		if (in_2) {
			table_1.insert(p_1->key, p_1->status, p_1->info);
			table_2.remove(g_key);
			commander_1->set_subdivision_table(table_1);
			commander_2->set_subdivision_table(table_2);
		}
		return 0;
	}
	int Infield::add_soldier(int g_key, int g_status, int team, Army::Soldier* g_soldier) {
		Subdivision* sub_1 = nullptr, * sub_2 = nullptr;
		sub_1 = commander_1->get_subdivision();
		sub_2 = commander_2->get_subdivision();
		Matrix::Table table_1, table_2;
		table_1 = sub_1->get_table();
		table_2 = sub_2->get_table();

		Matrix::ConstTableIt p_1, p_2;
		bool in_1 = true, in_2 = true;
		if (team == 1) {
			try {
				p_1 = table_1.find(g_key);
			}
			catch (std::exception) {
				in_1 = false;
			}
			if (in_1) {
				std::cout << "There is such soldier already!";
				return -1;
			}
			table_1.insert(g_key, g_status, g_soldier);
			commander_1->set_subdivision_table(table_1);
		}
		if (team == 2) {
			try {
				p_2 = table_2.find(g_key);
			}
			catch (std::exception) {
				in_2 = false;
			}
			if (in_2) {
				std::cout << "There is such soldier already!";
				return -1;
			}
			table_2.insert(g_key, g_status, g_soldier);
			commander_2->set_subdivision_table(table_2);
		}
		return 0;
	}
	Matrix::Table Infield::get_table(int team) const {
		Subdivision* sub_1 = nullptr, * sub_2 = nullptr;
		sub_1 = commander_1->get_subdivision();
		sub_2 = commander_2->get_subdivision();
		Matrix::Table table_1, table_2;
		table_1 = sub_1->get_table();
		table_2 = sub_2->get_table();

		switch (team) {
		case 1:
			return table_1;
		case 2:
			return table_2;
		default:
			throw std::exception("Wtf did u enter as team");
		}
	}
	Field_commander::~Field_commander() {
		Army::Field_fighter::~Field_fighter();
		Army::Staff_officer::~Staff_officer();
	}
	Max_commander::~Max_commander() {
		Army::Staff_officer::~Staff_officer();
	}
}