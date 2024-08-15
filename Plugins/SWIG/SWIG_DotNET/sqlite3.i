#pragma once

#include <algorithm>
#include <cctype>
#include <string>
#include <functional>
#include <ctime>
#include <tuple>
#include <memory>
#include <vector>
#include <optional>

struct sqlite_config;

namespace sqlite {

    template<class T>
	using optional = std::optional<T>;

	class database;
	class database_binder;

	template<std::size_t> class binder;

	typedef std::shared_ptr<sqlite3> connection_type;

	template<typename Tuple, int Element = 0, bool Last = (std::tuple_size<Tuple>::value == Element)> struct tuple_iterate {
		static void iterate(Tuple& t, database_binder& db) {
			get_col_from_db(db, Element, std::get<Element>(t));
			tuple_iterate<Tuple, Element + 1>::iterate(t, db);
		}
	};

	template<typename Tuple, int Element> struct tuple_iterate<Tuple, Element, true> {
		static void iterate(Tuple&, database_binder&) {}
	};

	class database {
	protected:
		std::shared_ptr<sqlite3> _db;

	public:
		database(const std::string &db_name, const sqlite_config &config = {}): _db(nullptr);

		database(const std::u16string &db_name, const sqlite_config &config = {}): _db(nullptr);

		database(std::shared_ptr<sqlite3> db): _db(db);

		database_binder operator<<(const std::string& sql);

		database_binder operator<<(const char* sql);

		database_binder operator<<(const std::u16string& sql);

		database_binder operator<<(const char16_t* sql);

		connection_type connection() const;

		sqlite3_int64 last_insert_rowid();

		template <typename Function>
		void define(const std::string &name, Function&& func);

		template <typename StepFunction, typename FinalFunction>
		void define(const std::string &name, StepFunction&& step, FinalFunction&& final);

	};

}
