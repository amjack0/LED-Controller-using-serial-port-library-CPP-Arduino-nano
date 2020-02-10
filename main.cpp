
#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];
char *port = "\\\\.\\COM4";


class led_controller{
    public:
        int force;
        int force_thr;

    led_controller(int force_acting, int force_threshold){
        force = force_acting;
        force_thr = force_threshold;
    }

    void check_connection(SerialPort arduino)
    {
        if(arduino.isConnected()){
        cout<<"Connection is made, Now I am talking."<<endl<<endl;
    }
    else{
		cout<<"Error in port name, I am NOT talking."<<endl<<endl;
	}
    }

    // Methods to turn LED Red,orange and Green
    void orange(SerialPort arduino)
    {
    //just make orange, set data to ONF and send it to LED controller
    // serial port is a Parent class.
    cout<<"Force is getting higher than threshold force. I am ORANGE" <<endl;
    string data2;
    data2 = "ONF";
    char *charArray = new char[data2.size() + 1];
    copy(data2.begin(), data2.end(), charArray);
    charArray[data2.size()] = '\n';

    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);
    cout<<">> "<<output<<endl;
    delete [] charArray;
    }

    void red(SerialPort arduino)
    {
        cout<<"Force is higher than threshold force. I am RED !" <<endl;
        string data;
        data = "ON";
    char *charArray = new char[data.size() + 1];
    copy(data.begin(), data.end(), charArray);
    charArray[data.size()] = '\n';

    //SerialPort arduino(port);
    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);
    cout<<">> "<<output<<endl;
    delete [] charArray;
    }

    void green(SerialPort arduino)
    {
        //SerialPort arduino(port);
        cout<<"Force is less than threshold force. I am GREEN !" <<endl;
        string data1;
        data1 = "OFF";

    char *charArray = new char[data1.size() + 1];
    copy(data1.begin(), data1.end(), charArray);
    charArray[data1.size()] = '\n';

    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);
    cout<<">> "<<output<<endl;
    delete [] charArray;
    }
};

int main(){
    //led_controller led_obj;
    SerialPort arduino(port);
    led_controller led_obj(100,100);
    //led_obj.check_connection(arduino);

	while(arduino.isConnected()){
            if (led_obj.force == led_obj.force_thr){
                    led_obj.orange(arduino);
            }

            if (led_obj.force > led_obj.force_thr){
                    led_obj.red(arduino);
            }

            if (led_obj.force < led_obj.force_thr){
                    led_obj.green(arduino);
            }
	}
}
