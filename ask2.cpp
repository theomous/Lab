#include <iostream>


using namespace std;

int main()
{
	float value;
	float x;
	float temp = 0.5;
	cout << "Give a number :";
    cin >> value;
    if(value <= 0 || value > 4000)
    {
    	cout << "Wrong input";
    	exit(0);
	}
	else
	{
		if (value <= 500)
		{
			x = value * temp + 5;
			cout << value << " kWh -> " << x << "$" << endl;
		}
		else
		{
			if (value <= 900)
			{
				x = 500*temp;
			    temp = 1.08*temp;
			    x = (value - 500)*temp + x + 5;
			    cout << "500 kWh -> 0.5$\n" << value-500 << " kWh -> " << temp << "$\n" << "Total: " << value << " kKh -> " << x << "$" << endl;
		    }
			else
			{
				if (value <= 1100)
				{
					x = 500*temp;
					temp = 1.08*temp;
			        x = 400*temp + x;
			        temp = 1.12*temp;
				    x = (value-900)*temp + x + 5;
					cout << "500 kWh -> 0.5$\n" << "400 kWh -> 0.54$\n" << value-900 << " kWh -> " << temp << "$\n" << "Total: "<< value << " kWh -> " << x << "$" << endl;
			    }
				else
				{
					if(value <= 4000)
					{
						x = 500*temp;
						temp = 1.08*temp;
						x = 400*temp + x;
						temp = 1.12*temp;
						x = 200*temp + x;
						temp = 1.20*temp;
						x = (value-1100)*temp + x + 5;
						cout << "500 kWh -> 0.5$\n" << "400 kWh -> 0.54$\n" << "200 kWh -> 0.6048\n" << value-1100 << " kWh -> " << temp << "\n" << "Total: " << value << " kWh -> " << x << "$" << endl;
					}
					    
				}
			}
		}
	}
	return 0;
}

