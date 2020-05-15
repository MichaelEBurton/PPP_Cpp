#include "../../../std_lib_facilities.h"

int main()
{
    int current = 1;

    int all_rice = 0;
    int msg_counter = 0;

    for(int i = 1; i <= 64; ++i){
        if(all_rice >= 1000 && msg_counter == 0){
            cout<<"Squares needed for the king to receive at least 1,000 grains of rice: "<<i<<"\n";
            ++msg_counter;
        } else if(all_rice >= 1000000 && msg_counter == 1){
            cout<<"Squares needed for the king to receive at least 1,000,000 grains of rice: "<<i<<"\n";
            ++msg_counter;
        } else if(all_rice >= 1000000000 && msg_counter == 2){
            cout<<"Squares needed for the king to receive at least 1,000,000,000 grains of rice: "<<i<<"\n";
            break;
        }
        all_rice += current;
        current *= 2;
    }
}