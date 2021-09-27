string c;
    cin >> c;
    for(int i = 0; i<c.length(); i++){
        if (c[i] == '(' || c[i]=='[' || c[i]=='{'){
            s.push(c[i]);
        }
        else if (c[i] == ')' || c[i]==']' || c[i]=='}'){
            if(s.top->data == c[i]){
                s.pop();
            }
            else{
                cout<<"bad"<<endl;
            }
        }
    }
    cout<<"good"<<endl;
    return 0;