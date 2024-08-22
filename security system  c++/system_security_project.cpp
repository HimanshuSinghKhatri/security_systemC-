#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
    int a,i=0;
    string text,old ,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2],cp[2];
    cout<<"       Security System   "<<endl;
    cout<<"________________________"<<endl<<endl;
    cout<<"       1.Register       "<<endl;
    cout<<"       2.LogIn       "<<endl;
    cout<<"       3.Change Password       "<<endl;
    cout<<"_______4.End Progeam_______"<<endl<<endl;
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:
            {
            cout<<"_____________________"<<endl<<endl;
            cout<<"-------Register------"<<endl;
            cout<<"please enter username:-"<<endl;
             cin.ignore();
           // cin>>name;
           getline(cin,name);
            cout<<"please enter the password:-"<<endl;
            cin>>password0;
            cout<<"please enter your age:-"<<endl;
            cin>>age;
            ofstream of1;
            of1.open("file.txt");
            if(of1.is_open())
            {
                of1<<name<<"\n";
                of1<<password0;
                cout<<"Registration Sucessfull"<<endl;
            }
            break;
            }
         case 2:
         	{
         		i=0;
         		cout<<"_____________________________"<<endl<<endl;
         		cout<<"|----------login------------|"<<endl;
         		cout<<"|___________________________|"<<endl<<endl;
         		 
         		ifstream of2;
         		of2.open("file.txt");
         		cout<<"please enter the username:-";
         		cin.ignore();
         		//cin>>user;
         		getline(cin,user);
         		cout<<"Please enter the password:-";
         		cin>>pass;
         		if(of2.is_open())
         		{
         			while(!of2.eof())
         			{
         				while(getline(of2,text))
         				{
         					istringstream iss(text);
         					iss>>word;;
         					creds[i]=word;
         					i++;
						 }
						 
						 if(user==creds[0]&& pass==creds[1])
						 {
						 	cout<<"---Log in sucessfull---";
						 	cout<<endl<<endl;
						 	cout<<"Username:"+name<<endl;
						 	cout<<"password:"+pass<<endl;
						 	cout<<"Age:"+age<<endl;
						 	
						 }
						 else
						 {
						 	cout<<endl<<endl;
						 	cout<<"Incorrect Credentials"<<endl;
						 	cout<<"|    1.press 2 to login               |"<<endl;
						 	cout<<"|    2.press 2 ro change password     |" <<endl;
							  break;
						 }
					 }
				 }
				 break;
	
			 }
			 case 3:
	{
	 i=0;
	 cout<<"------------chnage password--------------"<<endl;
	 ifstream of0;
	 of0.open("file,txt");
	 cout<<"Enter the old password:-";
	// cin>>old;
	getline(cin,old);
	 if(of0.is_open())
	 {
	 	while(of0.eof())
	 	{
	 		while(getline(of0,text))
	 		{
	 			istringstream iss(text);
	 			iss>>word1;
	 			cp[i]=word1;
	 			i++;
			 }
			 if(old==cp[1])
			 {
			 	of0.close();
			 	ofstream of1;
			 	if(of1.is_open())
			 	{
			 		cout<<"Enter your new password:-";
			 		cin>>password1;
			 		cout<<"Enter your password again:-";
			 		
			 		cin>>password2;
			 		if(password1==password2)
			 		{
			 			of1<<cp[0]<<"\n";
			 				of1<<password1;
			 				cout<<"Password changed sucessfully"<<endl;
					 }
					 else
					 {
					 	of1<<cp[0]<<"\n";
					 	of1<<old;
					 	cout<<"Password do not match"<<endl;
					 }
				 }
			 }
			 else
			 {
			 	cout<<"Please enter a valid password"<<endl;
			 	break;
			 }
		 }
	 }
	 break;
	}
			 	
		    case 4:
		    	{
				
		    	cout<<"___________Thankyou!____________";
		        break;
              }  
        default:
        	cout<<"enter a valid chocie";
    }
}
while(a!=4);
return 0;
}
