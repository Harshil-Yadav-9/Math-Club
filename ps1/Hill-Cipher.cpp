#include<bits/stdc++.h>
using namespace std;

//divide the element's of adjugate matrix by the value of determinant
int mod_inv(int det){
    det = ((det % 26) + 26) % 26;
    for(int i = 1;i < 26;i++){
        if((det * i) % 26 == 1) return i;
    }
    return -1;
}

int main(){

    //hint word
    string hint;
    cin >> hint;

    //matrix of hint
    vector<vector<int>>mat(3,vector<int>(3));
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            mat[i][j] = hint[3*i+j]-'A'+0;
        }
    }

    //calculate the value of determinant by Sarrus' Rule
    int det = 0;
    for(int i = 0;i < 3;i++){
        det += mat[0][i]*mat[1][(i+1) % 3]*mat[2][(i+2) % 3];
        det -= mat[2][i]*mat[1][(i+1) % 3]*mat[0][(i+2) % 3];
    }

    //if inverse matrix exist or not
    int invr_multi = mod_inv(det);
    if(invr_multi == -1){
        cout << "Invalid hint(key)!! please provide another hint(key)\n";
        return 0;
    }

    //buliding an inverse matrix of the hint matrix
    vector<vector<int>>invr_mat(3,vector<int>(3));
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            int temp = mat[(i+1) % 3][(j+1) % 3] * mat[(i+2) % 3][(j+2) % 3] - mat[(i+1) % 3][(j+2) % 3] * mat[(i+2) % 3][(j+1) % 3];
            invr_mat[j][i] = ((temp * invr_multi % 26) + 26) % 26;
        }
    }

    //text message
    string text_msg;
    cin.ignore();
    getline(cin,text_msg);
    string dup = text_msg;
    text_msg.erase(remove(text_msg.begin(),text_msg.end(),' '),text_msg.end());

    //vector of three alphabets or symbols of text messages
    int size = text_msg.size();
    int s1 = size/3;
    vector<vector<int>>vecs(s1,vector<int>(3));
    for(int i = 0;i < s1;i++){
        for(int j = 0;j < 3;j++){
            vecs[i][j] = text_msg[3*i+j] - 'A' + 0;
        }
    }

    //matrix multiplication with vectors of text message
    string temp_ans = "";
    for(int i = 0;i < s1;i++){
        for(int j = 0;j < 3;j++){
            int temp = 0;
            for(int k = 0;k < 3;k++){
                temp += invr_mat[j][k]*vecs[i][k];
            }
            temp_ans += char(((temp % 26) + 26) % 26 + 'A');
        }
    }

    //final encoded message with spaces
    string final_ans = "";
    int i = 0;
    for(char c : dup){
        if(c != ' '){
            final_ans += temp_ans[i];
            i++;
        }
        else {
            final_ans += ' ';
        }
    }

    cout << final_ans << "\n";

    return 0;
}
