// // Write a C++ program to implement LALR parsing ?
// // C++ program for implementation of LALR Parser
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // Parsing table
//     int table[10][5] = {{5, 0, 0, 4, 0},
//                         {0, 6, 0, 0, 0},
//                         {0, -2, 7, 0, -2},
//                         {0, -4, -4, 0, -4},
//                         {5, 0, 0, 4, 0},
//                         {0, -6, -6, 0 ,-6},
//                         {5 ,0 ,0 ,4 ,0},
//                         {5 ,0 ,0 ,4 ,0},
//                         {0 ,-1 ,0 ,0 ,-3},
//                         {0 ,-5 ,-5 ,0 ,-5}};
//     // Goto table
//     int goto_table[10][3] = {{1 ,2 ,3},
//                              {0 ,0 ,0},
//                              {0 ,0 ,0},
//                              {0 ,0 ,0},
//                              {8 ,2 ,3},
//                              {0 ,0 ,0},
//                              {9 ,2 ,3},
//                              {10,2 ,3},
//                              {0 ,0 ,11},
//                              {0 ,0 ,12}};
//     // Input string
//     string str = "i+i*i$";
//     // Stack to store states
//     stack<int> st;
//     st.push(0);
//     // Start parsing
//     int i = 1;
//     while (true)
//     {
//         int state = st.top();
//         int col = -1;
//         if (str[i] == 'i')
//             col = 1;
//         else if (str[i] == '+')
//             col = 2;
//         else if (str[i] == '*')
//             col = 3;
//         else if (str[i] == '$')
//             col = 4;
//         if (col == -1)
//             break;
//         int next_state = table[state][col];
//         if (next_state > 100)
//         {
//             cout << "Reduce " << next_state-100 << endl;
//             st.pop();
//             st.pop();
//             st.push(goto_table[st.top()][next_state-100-1]);
//         }
//         else if (next_state < 100 && next_state >= 10)
//         {
//             cout << "Shift " << next_state << endl;
//             st.push(next_state);
//             i++;
//         }
//         else if (next_state < 10)
//         {
//             cout << "Error" << endl;
//             break;
//         }
//     }
// }