#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

void printPlane(int x, int y);
void printCloud(int x, int y);

void ClearScreen()
    {
    int n;
    for (n = 0; n < 10; n++)
      cout<<"\n\n\n\n\n\n\n\n\n\n";
    }

int main() {
	/*cout<<"#############################################################"<<endl;
	cout<<"#                    _                                      #"<<endl;  
	cout<<"#                  -=\\`\\                                    #"<<endl;  
	cout<<"#              |\\ ____\\_\\__                                 #"<<endl;  
	cout<<"#            -=\\c`\"\"\"\"\"\"\" \"`)                               #"<<endl;  
	cout<<"#               `~~~~~/ /~~'\                                #"<<endl;  
	cout<<"#                 -==/ /                                    #"<<endl;  
	cout<<"#                   '-'                                     #"<<endl;  
	cout<<"#                  _  _                                     #"<<endl;  
	cout<<"#                 ( `   )_                                  #"<<endl;  
	cout<<"#                (    )    `)                               #"<<endl;  
	cout<<"#              (_   (_ .  _) _)                             #"<<endl;  
	cout<<"#                                             _             #"<<endl;  
	cout<<"#                                            (  )           #"<<endl;  
	cout<<"#             _ .                         ( `  ) . )        #"<<endl;  
	cout<<"#           (  _ )_                      (_, _(  ,_)_)      #"<<endl;  
	cout<<"#         (_  _(_ ,)                                        #"<<endl;  
	cout<<"#############################################################"<<endl;*/

	cout<<"\033[0;#m";

	for (int i=0; i<20; i++) {
		ClearScreen();
		printCloud(20-i,0);
		printPlane(i,5);
		usleep(500000);
	}

	return 0;
}

void printCloud(int x, int y) {
	string cloud[] = { "   ( `   )_     ",
		"  (    )    `)  ",
		"(_   (_ .  _) _)" };

	for (int i=0; i<3; i++) {
		for (int r=0; r<x; r++) {
			cout<<" ";
		}
		cout<<cloud[i]<<endl;
	}
}

void printPlane(int x, int y) {
	string plane[] = { "        _                ",
		"      -=\\`\\            ",
		"  |\\ ____\\_\\__        ",
		"-=\\c`\"\"\"\"\"\"\" \"`)",
		"   `~~~~~/ /~~'\         ",
		"     -==/ /              ",
		"       '-'               " };

	for (int i=0; i<y; i++) {
		cout<<endl;
	}
	for (int j=0; j<7; j++) {
		for (int r=0; r<x; r++) {
			cout<<" ";
		}
		cout<<plane[j]<<endl;
	}
}
