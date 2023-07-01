#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
using namespace std;
void welcome()
{
    cout<<"              **************************************"<<endl;
    cout<<"              **************************************"<<endl;
    cout<<"              **                                  **"<<endl;
    cout<<"              **            WELCOME TO            **"<<endl;
    cout<<"              **           STOCKING  IT           **"<<endl;
    cout<<"              **  YOUR ONE AND ONLY STOCK BROKER  **"<<endl;
    cout<<"              **                                  **"<<endl;
    cout<<"              **************************************"<<endl;
    cout<<"              **************************************"<<endl;

    cout<<endl<<"    Please Select from the options below , You are a : "<<endl;
    cout<<"    1 . Admin"<<endl;
    cout<<"    2 . User"<<endl;
}
int upd = 1;
string s;
float b = 0;
int y = 0, n = 1;
vector<float> v{1644, 937, 2735, 6657, 500, 2471, 1126};
vector<float> v1{1.16, 1.18, 1.23, 4.20, 4.90, 1.23, 4.94};
vector<string> v2{"HDFCBank", "ICICIBank", "HDFC", "BajajFinance", "TataMotors", "RIL", "IndusIndBank"};
int login(int n1)
{
    switch(n1)
    {
    case 1 :
    {
        string userid, password, id, pass;
        int count2;
mm1 :
        cout<<"     Enter UserId : ";
        cin>>userid;
        cout<<"     Enter Password : ";
        cin>>password;
        ifstream input("records.txt");
        while(input>>id>>pass)
        {
            if(id == userid && pass == password)
            {
                count2 = 1;
                system("cls");
            }
        }
        input.close();
        if(count2 == 1)
        {
            cout<<"     Login Successful"<<endl;
        }
        else
        {
            cout<<"     Login Failed"<<endl;
            cout<<"     Press any key to try again"<<endl;
            getch();
            system("cls");
            goto mm1;
        }
        return y;
    }
    break;
    case 2 :
    {
        int c3;
mm4 :
        cout<<"     Please enter a choice : "<<endl;
        cout<<"     1 . New User"<<endl;
        cout<<"     2 . Existing User"<<endl;
        cin>>c3;
        switch(c3)
        {
        case 1 :
        {
            string ruserid, rpassword, rid, rpass;
            cout<<"     Enter New UserId : ";
            cin>>ruserid;
            cout<<"     Enter New Password : ";
            cin>>rpassword;
            ofstream f1("records.txt", ios::app);
            f1<<ruserid<<' '<<rpassword<<endl;
            f1.close();
            system("cls");
            cout<<"     Registration Successful !!!"<<endl;
            cout<<"     Restart to login"<<endl;
            getch();
            system("cls");
            return n;
        }
        break;
        case 2 :
        {
            string userid1, password1, id1, pass1;
            int count1;
mm3 :
            cout<<"     Enter UserId : ";
            cin>>userid1;
            cout<<"     Enter Password : ";
            cin>>password1;
            ifstream input1("records.txt");
            while(input1>>id1>>pass1)
            {
                if(id1 == userid1 && pass1 == password1)
                {
                    count1 = 1;
                    system("cls");
                }
            }
            input1.close();
            if(count1 == 1)
            {
                cout<<"     Login Successful"<<endl;
                return 0;
            }
            else
            {
                system("cls");
                cout<<"     Login Failed"<<endl;
                cout<<"     Press any key to try again"<<endl;
                getch();
                system("cls");
                goto mm3;
            }
        }
        break;
        }
    }
    break;
    }
}
struct customer
{
    string name;
    string accno;
    float bal = 0;
};
class market
{
public :
    struct customer c;
    //virtual void displaydata()=0;
    void setdata()
    {
        cout<<"Enter the Name : ";
        cin>>c.name;
        ifstream file("customerinfo.txt");
        while(getline(file, s))
        {
            upd++;
        }
        c.accno = to_string(upd);
        file.close();
        cout<<"Assigned Account Number : "<<c.accno<<endl;
        upd = 0;
        cout<<"Enter the Balance in your account(Minium balance 1000) : ";
mm5 :
        cin>>b;
        if(b < 1000)
        {
            system("cls");
            cout<<"Minimum balance should be 1000"<<endl;
            cout<<"Enter balance again : ";
            goto mm5;
        }
        else
        {
            c.bal = b;
            cout<<"Balance entered !!"<<endl;
        }
        ofstream fil("customerinfo.txt", ios::app);
        fil<<endl;
        fil.close();
        string s3 = c.accno;
        s3 = s3 + ".txt";
        ofstream f2(s3, ios::app);
        f2<<c.name<<' '<<c.accno<<' '<<c.bal<<endl;
        f2.close();
        cout<<"             **** Profile Completed ****"<<endl;
        cout<<"     **** You are ready to play in the market ****"<<endl;
        cout<<"     Press any key to continue ..."<<endl;
        getch();
        system("cls");
    }
};
class buying : public market
{
public :
    string type;
    float quantity;
    buying()
    {
        type = "BUY";
        quantity = 1;
    }
    buying(string s)
    {
        type = "BUY";
        quantity = 1;
        c.accno = s;
        c.bal = 9000;
    }
    void buy()
    {
        int i;
        system("cls");
mm6 :
        fstream ptr;
        ptr.open("pricelist.txt", ios::in);
        if(ptr.is_open())
        {
            string str;
            while(getline(ptr, str))
            {
                cout<<str<<endl;
            }
            ptr.close();
        }
        cout<<endl<<"     Enter the choice of buying : ";
        cin>>i;
        cout<<"     Enter the quantity : ";
        cin>>quantity;
        if(v[i]*quantity > c.bal)
        {
            cout<<"Balance overexceeded"<<endl;
            cout<<"Try Again !!"<<endl;
            cout<<"Press any key to continue"<<endl;
            getch();
            system("cls");
            goto mm6;
        }
        else
        {
            cout<<"Share brought Successfully !!!"<<endl;
            cout<<"Press any key to continue !!"<<endl;
            getch();
            system("cls");
            float balance1 = c.bal - (v[i-1]*quantity);
            string s2 = c.accno;
            s2 = s2 + ".txt";
            ofstream f2(s2, ios::app);
            f2<<v2[i-1]<<' '<<quantity<<' '<<type<<' '<<"Current Balance : "<<' '<<balance1<<endl;
            f2.close();
        }
    }
};
class selling : public market
{
public :
    string type;
    float squantity;
    int i1;
    selling()
    {
        squantity = 0;
        type = "SELL";
    }
    selling(string s, float d)
    {
        squantity = 0;
        type = "SELL";
        c.accno = s;
        c.bal = d;
    }
    friend class buying;
    void sell()
    {
        system("cls");
mm7 :
        fstream ptr;
        ptr.open("pricelist.txt", ios::in);
        if(ptr.is_open())
        {
            string str;
            while(getline(ptr, str))
            {
                cout<<str<<endl;
            }
            ptr.close();
        }
        cout<<endl<<"     Enter the choice of selling : ";
        cin>>i1;
        cout<<"Enter the quantity : ";
        cin>>squantity;
        fstream ptr1;
        string s4 = c.accno;
        s4 = s4 + ".txt";
        ptr1.open(s4, ios::in);
        string s5;
        int cnt = 0;
        while(ptr1>>s5)
        {
            if(v2[i1-1] == s5)
            {
                cnt++;
            }
        }
        ptr1.close();
        if(cnt == 0)
        {
            cout<<"     No such share bought !!!"<<endl;
            cout<<"     Press any key to try again !"<<endl;
            getch();
            system("cls");
            goto mm7;
        }
        else
        {
            cout<<"Share sold successfully !!!"<<endl;
            cout<<"Press any key to continue !"<<endl;
            float balance2 = c.bal + (v[i1-1]*squantity*v1[i1-1]);
            string s2 = c.accno;
            s2 = s2 + ".txt";
            ofstream f2(s2, ios::app);
            f2<<v2[i1-1]<<' '<<squantity<<' '<<type<<' '<<"Current Balance : "<<' '<<balance2<<endl;
            f2.close();
            getch();
        }
    }
};
class loan : public market
{
public :
    float bala;
    string ac;
    float lo;
    loan()
    {
        string s14;
        cout<<"     Enter Account Number : ";
        cin>>s14;
        ac = s14;
        fstream ptr8;
        string s15 = s14 + ".txt";
        string s16, s17 = "";
        string s18;
        int i9 = 0, c15 = 0;
        ifstream inv(s15);
        while(getline(inv, s18))
        {
            i9++;
        }
        ptr8.open(s15, ios::in);
        while(getline(ptr8, s16))
        {
            c15++;
            if(c15 == i9)
            {
                for(int p = s16.size() - 4 ; p < s16.size() ; p++)
                {
                    s17 = s17 + s16[p];
                }
            }
        }
        ptr8.close();
        float d=0;
        for(int o = 0 ; o < s17.size() ; o++)
        {
            d = d + int(s17[o]-48)*pow(10, s17.size() - 1 - o);
        }
        bala = d;
    }
    void take()
    {
        string s20 = ac + ".txt";
        float bor;
        cout<<"     Enter the amount you want to borrow : ";
        cin>>bor;
        bala = bala + bor;
        ofstream f10(s20, ios::app);
        f10<<"Loan Acquired"<<' '<<"Current Balance : "<<bala<<endl;
        f10.close();
        cout<<"     Loan Granted !!!"<<endl;
        cout<<"     Press any key to continue ..."<<endl;
        getch();
        system("cls");
    }
    loan& operator!()
    {
        this->take();
    }
};
void info()
{
    fstream ptr;
    ptr.open("pricelist.txt", ios::in);
    if(ptr.is_open())
    {
        string str;
        while(getline(ptr, str))
        {
            cout<<str<<endl;
        }
        ptr.close();
    }
}
int main()
{
mm :
    welcome();
    int c1, c2, c4, p;
    cin>>c1;
    switch(c1)
    {
    case 1 :
        system("cls");
        c4 = login(1);
        break;
    case 2 :
        system("cls");
        c4 = login(2);
        break;
    default :
        cout<<"     Wrong choice entered !!!"<<endl;
        cout<<"     Press any key to return to Main Menu"<<endl;
        getch();
        system("cls");
        goto mm;
    }
    if(c1 == 1)
    {
mm20 :
        cout<<"     Enter the details of the new share : "<<endl;
        string name, price, chg, perchg, value;
        cout<<"     Name : ";
        cin>>name;
        cout<<"     Price : ";
        cin>>price;
        cout<<"     Change : ";
        cin>>chg;
        cout<<"     Percentage Change : ";
        cin>>perchg;
        cout<<"     Value(in cr) : ";
        cin>>value;
        ofstream g1("pricelist.txt", ios::app);
        g1<<name<<' '<<price<<' '<<chg<<' '<<perchg<<' '<<value<<endl;
        g1.close();
        cout<<"     Share added successfully !!!"<<endl;
mm21 :
        cout<<"     Press 1 to add another share"<<endl;
        cout<<"     Press 2 to logout"<<endl;
        int w;
        cin>>w;
        if(w == 1)
        {
            goto mm20;
        }
        else if(w == 2)
        {
            system("cls");
            goto mm;
        }
        else
        {
            cout<<"     Wrong Choice !!"<<endl;
            cout<<"     Press any key to enter choice again"<<endl;
            getch();
            goto mm21;
        }
    }
    if(c4==1)
    {
        market *m = new buying();
        m->setdata();
    }
    int chc;
mm10 :
    cout<<"     Please choice the action you would like to perform : "<<endl;
    cout<<"     1 . Stock Info "<<endl;
    cout<<"     2 . Buy Stock "<<endl;
    cout<<"     3 . Sell Stock "<<endl;
    cout<<"     4 . Check portfolio "<<endl;
    cout<<"     5 . Acquire Loan "<<endl;
    cout<<"     6 . Logout "<<endl<<endl;
    cin>>chc;
    switch(chc)
    {
    case 1 :
    {
        system("cls");
        info();
        cout<<"Press any key to continue ... "<<endl;
        getch();
        system("cls");
        goto mm10;
    }
    break;
    case 2 :
    {
        string s7;
        cout<<"Enter Account Number : ";
        cin>>s7;
        system("cls");
        buying b(s7);
        b.buy();
        cout<<endl<<"Press any key to continue ... "<<endl;
        getch();
        system("cls");
        goto mm10;
    }
    break;
    case 3 :
    {
        string s11;
        cout<<"Enter Account Number : ";
        cin>>s11;

        fstream ptr3;
        string s8 = s11 + ".txt";
        string s9, s10 = "";
        string s12;
        int i8 = 0, c14 = 0;
        ifstream in(s8);
        while(getline(in, s12))
        {
            i8++;
        }
        ptr3.open(s8, ios::in);
        while(getline(ptr3, s9))
        {
            c14++;
            if(c14 == i8 - 1)
            {
                for(p = s9.size() - 4 ; p < s9.size() ; p++)
                {
                    s10 = s10 + s9[p];
                }
            }
        }
        ptr3.close();
        float d=0;
        for(int o = 0 ; o < s10.size() ; o++)
        {
            d = d + int(s10[o]-48)*pow(10, s10.size() - 1 - o);
        }
        system("cls");
        selling s(s11, d);
        s.sell();
        cout<<endl<<"Press any key to continue ... "<<endl;
        getch();
        system("cls");
        goto mm10;
    }
    break;
    case 4 :
    {
        system("cls");
        string s12, s13;
        cout<<"     Enter Account Number : ";
        cin>>s12;
        s12 = s12 + ".txt";
        fstream ptr7;
        ptr7.open(s12, ios::in);
        if(ptr7.is_open())
        {
            string str;
            while(getline(ptr7, s13))
            {
                cout<<s13<<endl;
            }
            ptr7.close();
        }
        cout<<endl<<"Press any key to continue ... "<<endl;
        getch();
        system("cls");
        goto mm10;
    }
    break;
    case 5 :
    {
        system("cls");
        loan l;
        !l;
        goto mm10;
    }
    break;
    case 6 :
    {
        system("cls");
        goto mm;
    }
    break;
    default :
    {
        cout<<"     Wrong choice entered !!!"<<endl;
        cout<<"     Press any key to return to main menu ..."<<endl;
        getch();
        system("cls");
        goto mm10;
    }
    }
    return 0;
}
