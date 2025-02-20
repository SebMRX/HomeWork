#include<iostream>

using namespace std;

class Negative
{
private:
    string message;
public:
    Negative(string message) : message(message) {}

    string getMessage()
    {
        return message;
    }
};

class ZeroDivision {};

int main()
{
    int load, truck; 
    double loadPerTruck;

    try
    {
       
        cout << "Enter number of packages to load: ";
        cin >> load;
        if (load < 0)
        {
            throw Negative("number of packages to load");
        }


        cout << "Enter number of trucks available: ";
        cin >> truck;
        if (truck < 0)
        {
            throw Negative("number of trucks to carry the load");
        }

        if (truck != 0)
        {
            loadPerTruck = load / static_cast<double>(truck);
            cout << "You have " << loadPerTruck << " packages per truck to load" << endl;
        }
        else
        {
            throw ZeroDivision();
        }
    }
    catch (Negative& e)
    {
        cerr << "Encountered negative number; mistake in " << e.getMessage() << endl;
    }
    catch (ZeroDivision&)
    {
        cerr << "You have no trucks available!" << endl;
    }

    cout << "Leaving the program" << endl;

    return 0;
}
