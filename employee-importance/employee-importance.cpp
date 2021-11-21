/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> &employees, int id,int i,int n){
        int sum=0;
        for(int j=0;j<n;j++){
            if(employees[j]->id==id){
                sum+=employees[j]->importance;
                int sz=employees[j]->subordinates.size();
                for(int k=0;k<sz;k++){
                  sum+=getImportance(employees,employees[j]->subordinates[k],j,n);  
                }
                return sum;
            }
        }
        return 0;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size();
        return getImportance(employees,id,0,n);
    }
};