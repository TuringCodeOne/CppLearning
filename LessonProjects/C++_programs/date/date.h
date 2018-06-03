#include<iostream>
using namespace std;

		class Date {
			static const int days_in_mouths[12];
		 private:
			 int year;
			 int mouth;
			 int day;
			void check();
		 public:
			explicit Date(int d = 1, int m = 1, int y = 1) {
				year = y; mouth = m; day = d;
				check();
			}
			void set_date();
			Date operator++();
			Date operator+=(const Date& dt);
			Date operator=(const Date& dt);
			explicit operator int() const;
			//Date operator-=
			//Date operator--
			friend std::ostream& operator<<(std::ostream& os, const Date& dt);
			friend Date operator+(const Date& dt1, const Date& dt2);
			friend bool operator==(const Date&dt1, const Date& dt2);
			friend bool operator>(const Date&dt1, const Date&dt2);
			//friend Date operator-
			//friend Date operator<
			//friend Date operator!=
		
		};
	    //const int Date::days_in_mouths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		 Date Date::operator++() {
			day++;
			check();
			return Date(day, mouth, year);
		}
		 Date Date::operator+=(const Date& dt) {
			day += dt.day, mouth += dt.mouth, year += dt.year;
			check();
			return Date(day , mouth, year );
		}
		 Date Date::operator=(const Date& dt) {
			year = dt.year;
			mouth = dt.mouth;
			day = dt.day;
			return Date(day, mouth, year);
		}
		  std::ostream& operator<<(std::ostream& os, const Date& dt){
			os << "\nyear: " << dt.year
				<< "\tmouth: " << dt.mouth
				<< "\tday: " << dt.day;
			return os;
        }
		 Date operator+(const Date& dt1, const Date& dt2) {
			return Date(dt1.day + dt2.day, dt1.mouth + dt2.mouth, dt1.year + dt2.year);
		}
		 bool operator==(const Date&dt1, const Date& dt2) {
			return (dt1.year == dt2.year&&dt1.mouth == dt2.mouth&&dt1.day == dt2.day) ? 1 : 0;
		}
		 bool operator>(const Date&dt1, const Date&dt2) {
			if (dt1.year < dt2.year) return 0;
			else if (dt1.year>dt2.year) return 1;
			else if (dt1.mouth > dt2.mouth) return 1;
			else if (dt1.mouth < dt2.mouth) return 0;
			else if (dt1.day < dt2.day) return 0;
			else return 1;
		}
		 Date::operator int() const {
			int total_days_in_mouths=0, count_m = mouth;
			while (count_m != 1) {
				total_days_in_mouths += days_in_mouths[mouth - 2];
				count_m--;
			}
			return (year -1)* 365 + total_days_in_mouths+ day;
		}

}