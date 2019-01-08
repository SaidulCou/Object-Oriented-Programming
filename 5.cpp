#include<bits/stdc++.h>
using namespace std;
int cnt=0;
map<int, string, greater <int> > mp,mp1,mp2;
class Date
{
public:
    int cnt=0,current_month,current_date,current_year;
    string str,s1,s2,s3,s4,s5;
    void getData()
    {
        time_t my_time = time(NULL);
        str=ctime(&my_time);
        istringstream ss(str);
        do
        {
            string word;
            ss >> word;
            //cout << word << endl;
            cnt++;
            // cout<<cnt<<endl;
            if(cnt==2)
            {

                if((word.compare("Jan")) == 0)
                {
                    current_month=1;
                }
                if((word.compare("Feb")) == 0)
                {
                    current_month=2;
                }
                if((word.compare("Mar")) == 0)
                {
                    current_month=3;
                }
                if((word.compare("Apr")) == 0)
                {
                    current_month=4;
                }

                if((word.compare("May")) == 0)
                {
                    current_month=5;
                }
                if((word.compare("Jun")) == 0)
                {
                    current_month=6;
                }
                if((word.compare("Jul")) == 0)
                {
                    current_month=7;
                }
                if((word.compare("Aug")) == 0)
                {
                    current_month=8;
                }

                if((word.compare("Sep")) == 0)
                {
                    current_month=9;
                }
                if((word.compare("Oct")) == 0)
                {
                    current_month=10;
                }
                if((word.compare("Nov")) == 0)
                {
                    current_month=11;
                }
                if((word.compare("Dec")) == 0)
                {
                    current_month=12;
                    //cout<<"month="<<month<<endl;
                }

            }
            if(cnt==3)
            {
                stringstream geek(word);
                int x = 0;
                geek >> x;
                current_date=x;
                //cout<<"Day="<<day<<endl;
            }
            if(cnt==5)
            {
                stringstream geek(word);
                int y = 0;
                geek >> y;
                current_year=y;
                //cout<<"Year="<<year<<endl;
            }
        }
        while (ss);
    }
    void Display()
    {
        //cout<<current_date<<" "<<current_month<<" "<<current_year<<endl;
    }
};
class Person
{
public:
    string name;
    int birth_date,birth_month,birth_year;
    Person() {}
    Person(string n,int a,int b,int c)
    {
        name=n;
        birth_date=a;
        birth_month=b;
        birth_year=c;
    }

};
class Player:public Person,public Date
{
public:
    int matches,innings,wicket,not_out,runs,calculated_date,calculated_month,calculated_year;;
    Person p;
    Player(){}
    Player(string a,int b,int c,int d,int e,int f,int g,int h,int i){
        name=a;
        birth_date=b;
        birth_month=c;
        birth_year=d;
        matches=e;
        innings=f;
        wicket=g;
        not_out=h;
        runs=i;
    }
    void info(Date c)
    {
            int temp=((wicket+not_out)*20+runs)/innings;
            int month[] = { 31, 28, 31, 30, 31, 30, 31,
                            31, 30, 31, 30, 31
                          };
            if (birth_date > c.current_date)
            {
                c.current_date = c.current_date + month[birth_month - 1];
                c.current_month = c.current_month - 1;
            }
            if (birth_month > c.current_month)
            {
                c.current_year = c.current_year - 1;
                c.current_month = c.current_month + 12;
            }

            calculated_date = c.current_date - birth_date;
            calculated_month = c.current_month - birth_month;
            calculated_year = c.current_year - birth_year;

            cout<<name<<"'s Age:: ";
             if(calculated_date<30 && calculated_month<12){
            cout<<"Day="<<calculated_date<<" "<<"Month="<<calculated_month<<" "<<"Year="<<calculated_year<<endl;
            }
            if(calculated_date>=30){
                 cout<<"Day="<<calculated_date-30<<" "<<"Month="<<calculated_month+1<<" "<<"Year="<<calculated_year<<endl;
            }
            if(calculated_month>=12){
                 cout<<"Day="<<calculated_date<<" "<<"Month="<<calculated_month-12<<" "<<"Year="<<calculated_year+1<<endl;
            }
            if(calculated_year>25 && calculated_year<=30 && cnt<4)
            {
                if(wicket==runs)
                {
                    mp1.insert(make_pair(wicket,name));
                }
                else
                {
                    mp1.insert(make_pair(wicket,name));
                    mp2.insert(make_pair(runs,name));
                }


            }
            else if(calculated_year>=20 && calculated_year<=25)
            {
                mp.insert(make_pair(temp,name));
                if(wicket==runs)
                {
                    mp1.insert(make_pair(wicket,name));
                }
                else
                {
                    mp1.insert(make_pair(wicket,name));
                    mp2.insert(make_pair(runs,name));
                }

            }
            else
            {
                cout<<"Not selected......"<<endl<<endl;
            }
        }
        void operator ++(){
                     cnt++;
                }
};
class Selected_player:public Player
{
public:
    void display33()
    {
        cout<<endl<<endl<<"Selected Players..."<<endl;
        cout<<"-------------"<<endl;
        int i=0,j=0;
        map<int,string> :: iterator it;
        for (it=mp1.begin() ; it!=mp1.end() ; it++)
        {

            if(i==0)
            {
                cout<<(*it).second<<" is selected as Spin bowler"<<endl<<endl;
            }
            if(i==1 or i==2)
            {
                cout<<(*it).second<<" is selected as First bowler"<<endl;
            }
            i++;
        }
        cout<<endl;
        for (it=mp2.begin() ; it!=mp2.end() ; it++)
        {
            if(j==0)
            {
                cout<<(*it).second<<" is selected as Wicket keeper"<<endl<<endl;
            }
            if(j==1 or j==2 or j==3 or j==4)
            {
                cout<<(*it).second<<" is selected as Bats Man"<<endl;
            }
            j++;
        }
        cout<<endl;
    }
};
int main()
{

    Date c;
    c.getData();
    c.Display();
    Player p;
    Player p1("Sakib_Al_Hasan",24,03,1990,9,18,36,7,870);
    p1.info(c);
    Player p2("Tamim_Iqbal",20,03,1997,8,16,0,3,960);
    p2.info(c);
    Player p3("Mahmudullah",4,02,1991,9,15,14,1,750);
    p3.info(c);
    Player p4("Summo_Sarkar",25,02,1998,4,8,4,0,620);
    p4.info(c);
    Player p5("Sabbir_Rahman",4,11,1991,6,12,3,0,570);
    p5.info(c);
    Player p6("Mominul_Haque",7,9,1998,9,18,0,4,1250);
    p6.info(c);
    Player p7("Musfikur_Rahim",9,06,1997,9,17,0,2,1110);
    p7.info(c);
    Player p8("Mehedi_Hasan",6,03,1997,5,10,25,1,320);
    p8.info(c);
    Player p9("Rubel_Hossain",01,01,1994,8,16,20,1,60);
    p9.info(c);
    Player p10("Shahadat_Hossain",01,11,1991,9,18,26,2,86);
    p10.info(c);
    Player p11("Nayeem_Hasan",02,12,2000,2,4,12,1,40);
    p11.info(c);

    Selected_player sp;
    sp.display33();
}

