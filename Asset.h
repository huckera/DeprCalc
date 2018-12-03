#include <cmath>

#define WIDTH 22


class Asset {


   public:
    const float cost; //cost of asset
    float s_value; //salvage value
    int u_life; //useful life in years
    int curr_year; //spent life in years
    float curr_depr; //current year depreciation
    float cum_depr; //cumulated_depreciation
    float net_value; //current net value

    Asset (float a, float b, int c) : cost (a), s_value (b), u_life (c), net_value (a) {curr_year=0; curr_depr=0; cum_depr=0;}

    };

//display asset depreciation data

std::ostream& operator<<(std::ostream& o, const Asset& a)
    {
    o << std::setw(5) << std::right << a.curr_year
    << std::setw(WIDTH) << a.curr_depr
    << std::setw(WIDTH) << a.cum_depr
    << std::setw(WIDTH) << a.net_value << std::endl;

    return o;
    };

//display title row

void disp_title()
    {
    std::cout << "Depreciation table\n\n\n";

    std::cout << std::setw(5) << std::right << "Year,"
    << std::setw(WIDTH) << std::right << "Current d."
    << std::setw(WIDTH) << std::right << "Cumulated d."
    << std::setw(WIDTH) << std::right << "Net value" << std::endl;
    };


//calculate depreciation table

void depr_table (Asset& a, int method, float mult)
    {

        switch (method)
        {

        //straight-line

        case 1:
        {
            disp_title();
            std::cout << a;

            for (int i = 1;i<=a.u_life;i++)
            {
            a.curr_year++;
            a.curr_depr = (a.cost - a.s_value)/a.u_life;
            a.cum_depr += a.curr_depr;
            a.net_value = a.cost - a.cum_depr;

            std::cout << a;
            }
            break;
        }
        //sum-of-year-digits

        case 2:
        {
            disp_title();
            std::cout << a;

            float sod = (pow(a.u_life, 2.0) + a.u_life)/2;
            float sdv = (a.cost - a.s_value) / sod;
            for (int i = 1;i<=a.u_life;i++)
            {
            a.curr_year++;
            a.curr_depr = sdv * ((a.u_life+1)-i);
            a.cum_depr += a.curr_depr;
            a.net_value = a.cost - a.cum_depr;

            std::cout << a;
            }
            break;
        }

        //net-based, fix-rate method

        case 3:
        {

            disp_title();
            std::cout << a;

            for (int i = 1;i<=a.u_life;i++)
            {
            a.curr_year++;
            a.curr_depr = a.net_value * (1 - (pow((a.s_value/a.cost),(1/(float)a.u_life))));
            a.cum_depr += a.curr_depr;
            a.net_value = a.cost - a.cum_depr;

            std::cout << a;
            }
            break;
        }

        //double declining method

        case 4:
        {

            disp_title();
            std::cout << a;

            for (int i = 1;i<=a.u_life;i++)
            {
            a.curr_year++;
            a.curr_depr = (a.net_value * mult)/a.u_life;
            a.cum_depr += a.curr_depr;
            a.net_value = a.cost - a.cum_depr;

            std::cout << a;
            }

            break;
        }



        }



    };

