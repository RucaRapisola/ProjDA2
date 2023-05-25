#include "TourismInfo/TourismGestor.h"
#include "StadiumShippingInfo/Gestor.h"
#include "RealWordlGraphsInfo/RealGestor.h"
#include "ExtraFullyConnectedGraphsInfo/ExtraGestor.h"
#include <ctime>
#include <cstdlib>
using namespace std;

TourismGestor auxfile;
Gestor auxfile2;
RealGestor auxfile4;
ExtraGestor auxfile5;

TourismGraph helptour;
Graph helpship;
Graph helpsta;
RealGraph helpreal1;
RealGraph helpreal2;
RealGraph helpreal3;
ExtraGraph helpextra25;
ExtraGraph helpextra50;
ExtraGraph helpextra75;
ExtraGraph helpextra100;
ExtraGraph helpextra200;
ExtraGraph helpextra300;
ExtraGraph helpextra400;
ExtraGraph helpextra500;
ExtraGraph helpextra600;
ExtraGraph helpextra700;
ExtraGraph helpextra800;
ExtraGraph helpextra900;
void clearScreen() {
    for (int i = 0; i < 20; i++) {
        cout << endl;
    }
}

void wait() {
    cout << endl;
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Pressione ENTER para continuar...";
    cout << endl;
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}
//3 functions for exercise 4.1 that show the execution time for a specific graph when doing backtracking funtion

void StadiumsmeasureExecutionTime() {
    clock_t startTime = clock();
    Vertex2* bruhh = helpsta.findVertex(0);
    std::vector<bool> visited;
    double min_distance=10000000.0;
    vector<int> min_path;
    vector<int> currentPath;
    for (int i=0; i< helpsta.getNumVertex();i++){
        visited.push_back(false);
    }
    double howmany = helpsta.backtrack(bruhh, visited, 0, 0.0, numeric_limits<double>::max(), bruhh,min_path,currentPath);
    clock_t endTime = clock();
    cout << "|| Minimum Path: ";
    for (int vertex : min_path) {
        cout << vertex << " -> ";
    }
    cout <<"0                   ||"<< endl;
    cout << "|| With this path we get a total distance of "<< howmany <<" which is the lowest we could get from      ||" <<endl;
    cout << "|| this graph. Any other path will take a distance higher that this one.                     ||" << endl;
    cout << "||                                                                                           ||"<< endl;
    std::cout << "|| Also, with this graph the backtracking algorithm took an execution time of: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds. ||" << std::endl;
    cout << "||___________________________________________________________________________________________||" << endl;
}
double StadiumsmeasureExecutionTimeOnly(){
    Vertex2* bruhh = helpsta.findVertex(0);
    std::vector<bool> visited;
    double min_distance=10000000.0;
    vector<int> min_path;
    vector<int> currentPath;
    for (int i=0; i< helpsta.getNumVertex();i++){
        visited.push_back(false);
    }
    clock_t startTime = clock();
    helpsta.backtrack(bruhh, visited, 0, 0.0, numeric_limits<double>::max(), bruhh,min_path,currentPath);
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}
void ShippingmeasureExecutionTime() {
    clock_t startTime = clock();
    Vertex2* bruhh = helpship.findVertex(0);
    std::vector<bool> visited;
    double min_distance=10000000.0;
    vector<int> min_path;
    vector<int> currentPath;
    for (int i=0; i< helpship.getNumVertex();i++){
        visited.push_back(false);
    }
    double howmany = helpship.backtrack(bruhh, visited, 0, 0.0, numeric_limits<double>::max(), bruhh,min_path,currentPath);
    clock_t endTime = clock();
    cout << "|| Minimum Path: ";
    for (int vertex : min_path) {
        cout << vertex << " -> ";
    }
    cout <<"0 ||"<< endl;
    cout << "|| With this path we get a total distance of "<< howmany <<" which is the lowest we could get from      ||" <<endl;
    cout << "|| this graph. Any other path will take a distance higher that this one.                     ||" << endl;
    cout << "||                                                                                           ||"<< endl;
    std::cout << "|| Also, with this graph the backtracking algorithm took an execution time of: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds.||" << endl;
    cout << "||___________________________________________________________________________________________||" << endl;
}
double ShippingmeasureExecutionTimeOnly(){
    Vertex2* bruhh = helpship.findVertex(0);
    std::vector<bool> visited;
    double min_distance=10000000.0;
    vector<int> min_path;
    vector<int> currentPath;
    for (int i=0; i< helpship.getNumVertex();i++){
        visited.push_back(false);
    }
    clock_t startTime = clock();
    helpship.backtrack(bruhh, visited, 0, 0.0, numeric_limits<double>::max(), bruhh,min_path,currentPath);
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

void TourismmeasureExecutionTime() {
    clock_t startTime = clock();
    Vertex* bruhh = helptour.findVertex(0);
    std::vector<bool> visited;
    double min_distance=10000000.0;
    vector<int> min_path;
    vector<int> currentPath;
    for (int i=0; i< helptour.getNumVertex();i++){
        visited.push_back(false);
    }
    double howmany = helptour.backtrack(bruhh, visited, 0, 0.0, numeric_limits<double>::max(), bruhh,min_path,currentPath);
    clock_t endTime = clock();
    cout << "|| Minimum Path: ";
    for (int vertex : min_path) {
        cout << vertex << " -> ";
    }
    cout <<"0                                                  ||"<< endl;
    cout << "|| With this path we get a total distance of "<< howmany <<" which is the lowest we could get from      ||" <<endl;
    cout << "|| this graph. Any other path will take a distance higher that this one.                     ||" << endl;
    cout << "||                                                                                           ||"<< endl;
    std::cout << "|| Also, with this graph the backtracking algorithm took an execution time of: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds.    ||" << std::endl;
    cout << "||___________________________________________________________________________________________||" << endl;
}

bool valid_int(const string& s);




int main(){
    /*
    auxfile.gestor_tourism(help);
    auxfile.gestor_travel(help);



    auxfile2.gestor_stadiums(help2);
    auxfile2.gestor_travel_stadiums(help2);
    auxfile2.gestor_shipping(help3);
    auxfile2.gestor_travel_shipping(help3);
    */
    /*
    Graph bruhhh;
    auxfile2.gestor_shipping(help2);
    auxfile2.gestor_travel_shipping(help2);
    bruhhh = help2;
    vector<Edge2> yesdaddy = bruhhh.primMST();
    double count =0.0;
    for (auto itr = yesdaddy.begin();itr!=yesdaddy.end();itr++){
        cout << itr->getOrig()->getId() << " -> " << itr->getDest()->getId() << endl;
        count += itr->getDistancia();
    }
    cout << "Min weight: " << count;
     */
     /*
    vector<int> preorder;
    helpship.findMinMSTAndPreorderTraversal(preorder);
    preorder.push_back(0);
    double count=0.0;
    for (int i=0;i<preorder.size()-1;i++){
        count += helpship.calculateNodeDistance(preorder[i],preorder[i+1]);
    }
    cout << "Optimal cost: " << count << endl;
     */
    /*
    ExtraGraph bruhh;
    auxfile5.gestor_900edges(help5);
    auxfile5.gestor_travel_900edges(help5);
    bruhh=help5;
     */
    /*
    auxfile2.gestor_stadiums(helpsta);
    auxfile2.gestor_travel_stadiums(helpsta);
    vector<int> preorder;
    helpsta.findMinMSTAndPreorderTraversal(preorder);
    preorder.push_back(0);
    double count=0.0;
    for (int i=0;i<preorder.size()-1;i++){
        count += helpsta.calculateNodeDistance(preorder[i],preorder[i+1]);
    }
    cout << "Optimal cost: " << count << endl;
    */
    /*
    // Call the primMST function to find the minimum spanning tree
    vector<Edge3> mst = help4.primMST();

    for (const Edge3& edge : mst) {
        cout << edge.getOrig()->getId() << " - " << edge.getDest()->getId() << " : " << edge.getDistancia() << endl;
    }
     */
    bool confirm_read_tour =false;
    bool confirm_read_ship =false;
    bool confirm_read_stad =false;
    bool confirm_read_real1 =false;
    bool confirm_read_real2 =false;
    bool confirm_read_real3 =false;
    bool confirm_read_extra25 =false;
    bool confirm_read_extra50 =false;
    bool confirm_read_extra75 =false;
    bool confirm_read_extra100 =false;
    bool confirm_read_extra200 =false;
    bool confirm_read_extra300 =false;
    bool confirm_read_extra400 =false;
    bool confirm_read_extra500 =false;
    bool confirm_read_extra600 =false;
    bool confirm_read_extra700 =false;
    bool confirm_read_extra800 =false;
    bool confirm_read_extra900 =false;
    vector<int> preorder;
    double count=0.0;

    int choice;
    string op_menu;
    do{
        clearScreen();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "||------------------------ MENU -------------------------||" << endl;
        cout << "|| Choose an option:                                     ||" << endl;
        cout << "||_______________________________________________________||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   1 - Algorithms to apply in a graph                  ||" << endl;
        cout << "||   2 - Information about a graph                       ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   0 - Leave                                           ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;

        cin >> op_menu;

        while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 2) {
            cout << endl;
            cout << "Invalid option! Try again: ";
            cin >> op_menu;
            cout << endl;
        }

        choice = stoi(op_menu);
        cout << endl;

        switch (choice) {
            case 0:
                choice =0;

                break;

            case 1:
                int ch1;
                choice = 1;

                do {

                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||------------------------ MENU -------------------------||" << endl;
                    cout << "|| Choose an option:                                     ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Backtracking Algorithm                          ||" << endl;
                    cout << "||   2 - Triangular Approximation Heuristic              ||" << endl;
                    cout << "||   3 - Other Heuristics                                ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Leave                                           ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;


                    cin >> op_menu;


                    while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 4) {
                        cout << endl;
                        cout << "Invalid option! Try again: ";
                        cin >> op_menu;
                        cout << endl;
                    }

                    ch1 = stoi(op_menu);

                    switch (ch1) {
                        case 0:
                            ch1 = 0;
                            break;
                        case 1:
                            ch1 = 1;
                            int chh1;
                            do{
                                clearScreen();
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << "||---------------- Backtracking Algorithm ---------------||" << endl;
                                cout << "||  Choose which graph you would like to apply           ||" << endl;
                                cout << "|| these function:                                       ||" << endl;
                                cout << "||_______________________________________________________||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   1 -Toy-Graphs -> Tourism graph                      ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   2 -Toy-Graphs -> Shipping graph                     ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   3 -Toy-Graphs -> Stadiums graph                     ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   4 -Demonstration about the feasibility of this      ||" << endl;
                                cout << "|| approach in different large graphs                    ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   0 - Leave                                           ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << endl;

                                cin >> op_menu;


                                while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 4) {
                                    cout << endl;
                                    cout << "Invalid option! Try again: ";
                                    cin >> op_menu;
                                    cout << endl;
                                }

                                chh1 = stoi(op_menu);

                                switch (chh1) {
                                    case 0:
                                        chh1=0;
                                        break;
                                    case 1:
                                        chh1 = 1;
                                        clearScreen();
                                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                        cout << "||----------------------------- Backtracking for tourism graph -------_----------------------||" << endl;
                                        cout << "|| Using the backtracking algorithm for this graph we get to know what the minimum path is,  ||" << endl;
                                        cout << "|| in other words, the path that visits all the nodes with the lowest distance and ends in   ||" << endl;
                                        cout << "|| the starting node.                                                                        ||" << endl;
                                        cout << "||___________________________________________________________________________________________||" << endl;
                                        cout << "||                                                                                           ||" << endl;
                                        if(!confirm_read_tour){
                                            auxfile.gestor_tourism(helptour);
                                            auxfile.gestor_travel(helptour);
                                            confirm_read_tour=true;
                                        }
                                        TourismmeasureExecutionTime();
                                        wait();
                                        break;
                                    case 2:
                                        chh1 = 2;
                                        clearScreen();
                                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                        cout << "||----------------------------- Backtracking for shipping graph -----------------------------||" << endl;
                                        cout << "|| Using the backtracking algorithm for this graph we get to know what the minimum path is,  ||" << endl;
                                        cout << "|| in other words, the path that visits all the nodes with the lowest distance and ends in   ||" << endl;
                                        cout << "|| the starting node.                                                                        ||" << endl;
                                        cout << "||___________________________________________________________________________________________||" << endl;
                                        cout << "||                                                                                           ||" << endl;
                                        if(!confirm_read_ship){
                                            auxfile2.gestor_shipping(helpship);
                                            auxfile2.gestor_travel_shipping(helpship);
                                            confirm_read_ship=true;
                                        }
                                        ShippingmeasureExecutionTime();

                                        wait();
                                        break;
                                    case 3:
                                        chh1 = 3;
                                        clearScreen();
                                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                        cout << "||----------------------------- Backtracking for stadiums graph -----------------------------||" << endl;
                                        cout << "|| Using the backtracking algorithm for this graph we get to know what the minimum path is,  ||" << endl;
                                        cout << "|| in other words, the path that visits all the nodes with the lowest distance and ends in   ||" << endl;
                                        cout << "|| the starting node.                                                                        ||" << endl;
                                        cout << "||___________________________________________________________________________________________||" << endl;
                                        cout << "||                                                                                           ||" << endl;
                                        if(!confirm_read_stad){
                                            auxfile2.gestor_stadiums(helpsta);
                                            auxfile2.gestor_travel_stadiums(helpsta);
                                            confirm_read_stad=true;
                                        }
                                        StadiumsmeasureExecutionTime();

                                        wait();
                                        break;
                                    case 4:
                                        chh1=4;
                                        clearScreen();
                                        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                        cout << "||------------------------------ Feasibility of this approach -------------------------------||" << endl;
                                        cout << "||___________________________________________________________________________________________||" << endl;
                                        cout << "|| The backtrack algorithm is a general algorithmic technique for solving problems by        ||" << endl;
                                        cout << "|| systematically exploring all possible solutions through a depth-first search.             ||" << endl;
                                        cout << "|| When it comes to graph problems, the feasibility of using the backtrack algorithm in      ||" << endl;
                                        cout << "|| different graph sizes is very significant. As the number of vertices and edges increases, ||" << endl;
                                        cout << "|| the time and memory requirements of the algorithm can grow exponentially. Therefore, the  ||" << endl;
                                        cout << "|| algorithm may become impractical for large graphs.                                        ||" << endl;
                                        cout << "|| An quick example is using this approach in the shipping graph which has 14 nodes and a    ||" << endl;
                                        cout << "|| total of 34 connections and the stadiums graph which has 11 nodes and 55 connections to   ||" << endl;
                                        cout << "|| compare the time complexity of backtrack in both graphs.                                  ||" << endl;
                                        cout << "||------------------------------------------------------------------------------------------ ||" << endl;
                                        if(!confirm_read_stad){
                                            auxfile2.gestor_stadiums(helpsta);
                                            auxfile2.gestor_travel_stadiums(helpsta);
                                            confirm_read_stad=true;
                                        }

                                        if(!confirm_read_ship){
                                            auxfile2.gestor_shipping(helpship);
                                            auxfile2.gestor_travel_shipping(helpship);
                                            confirm_read_ship=true;
                                        }

                                        cout << "|| Execution time of backtrack for shipping graph: " << ShippingmeasureExecutionTimeOnly() << " seconds                             ||" << endl;
                                        cout << "||                                                                                           ||"<< endl;
                                        cout << "|| Execution time of backtrack for stadiums graph: " << StadiumsmeasureExecutionTimeOnly() << " seconds                             ||" << endl;
                                        cout << "||___________________________________________________________________________________________||" << endl;
                                        wait();
                                        break;
                                    default:
                                        clearScreen();
                                        cout << "Invalid option! Try again." << endl;
                                        wait();
                                        break;
                                }

                            }while (chh1!=0);
                            break;
                        case 2:
                            ch1 = 2;
                            int chhh2;
                            do{
                                clearScreen();
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << "||--------- Triangular Approximation Heuristic  ---------||" << endl;
                                cout << "||-------------------------------------------------------||" << endl;
                                cout << "||  There are 3 types of graph that you can apply these  ||" << endl;
                                cout << "|| function which are small,medium and large graphs.     ||" << endl;
                                cout << "||  Choose one of them:                                  ||" << endl;
                                cout << "||_______________________________________________________||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   1 -Small graphs (Toy-Graphs)                        ||" << endl;
                                cout << "||   2 -Medium graphs (Extra_Fully_Connected_Graphs)     ||" << endl;
                                cout << "||   3 -Large graphs (Real-World-Graphs)                 ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   0 - Leave                                           ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << endl;

                                cin >> op_menu;


                                while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 3) {
                                    cout << endl;
                                    cout << "Invalid option! Try again: ";
                                    cin >> op_menu;
                                    cout << endl;
                                }

                                chhh2 = stoi(op_menu);

                                switch (chhh2) {
                                    case 0:
                                        chhh2 = 0;
                                        break;
                                    case 1:
                                        chhh2=1;
                                        int chhh3;
                                        do{
                                            clearScreen();
                                            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                            cout << "||--Triangular Approximation Heuristic for small graphs--||" << endl;
                                            cout << "||-------------------------------------------------------||" << endl;
                                            cout << "|| Choose which graph you want to apply these function:  ||" << endl;
                                            cout << "||                                                       ||" << endl;
                                            cout << "||   1 -Tourism graph                                    ||" << endl;
                                            cout << "||   2 -Shipping graph                                   ||" << endl;
                                            cout << "||   3 -Stadium graph                                    ||" << endl;
                                            cout << "||                                                       ||" << endl;
                                            cout << "||   0 - Leave                                           ||" << endl;
                                            cout << "||                                                       ||" << endl;
                                            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                            cout << endl;

                                            cin >> op_menu;


                                            while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 3) {
                                                cout << endl;
                                                cout << "Invalid option! Try again: ";
                                                cin >> op_menu;
                                                cout << endl;
                                            }

                                            chhh3 = stoi(op_menu);

                                            switch (chhh3) {
                                                case 0:
                                                    chhh3=0;
                                                    break;
                                                case 1:
                                                    chhh3=1;
                                                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                                    cout << "||--------------------Triangular Approximation Heuristic for small graphs--------------------||" << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    cout << "|| To use this approach in this graph, firstly it´s used the prim´s algorithm to get the prim||" << endl;
                                                    cout << "|| algorithm to get the Minimum Spanning Tree. Only then using Pre-Order Traversal           ||" << endl;
                                                    cout << "|| (left to right) it is calculated the distance.As Tourism graph is a fully connected graph,||" << endl;
                                                    cout << "|| it is not necessary to calculate any distance between two nodes, which means that         ||" << endl;
                                                    cout << "|| Haversine distance computation is not used.                                               ||" << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    if(!confirm_read_tour){
                                                        auxfile.gestor_tourism(helptour);
                                                        auxfile.gestor_travel(helptour);
                                                        confirm_read_tour=true;
                                                    }
                                                    helptour.findMinMSTAndPreorderTraversal(preorder);
                                                    cout << "0" << endl;
                                                    preorder.push_back(0);
                                                    count=0.0;
                                                    for (int i=0;i<preorder.size()-1;i++){
                                                        count += helptour.calculateNodeDistance(preorder[i],preorder[i+1]);
                                                    }
                                                    cout << "Optimal cost: " << count << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    preorder.clear();
                                                    wait();
                                                    break;
                                                case 2:
                                                    chhh3=2;
                                                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                                    cout << "||--------------------Triangular Approximation Heuristic for small graphs--------------------||" << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    cout << "|| To use this approach in this graph, firstly it´s used the prim´s algorithm to get the prim||" << endl;
                                                    cout << "|| algorithm to get the Minimum Spanning Tree. Only then using Pre-Order Traversal           ||" << endl;
                                                    cout << "|| (left to right) it is calculated the distance.As shipping graph is a fully connected graph||" << endl;
                                                    cout << "|| it is necessary to calculate the distance between two nodes that are not connected, which ||" << endl;
                                                    cout << "|| means that Haversine distance computation will be used.                                   ||" << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    if(!confirm_read_ship){
                                                        auxfile2.gestor_shipping(helpship);
                                                        auxfile2.gestor_travel_shipping(helpship);
                                                        confirm_read_ship=true;
                                                    }
                                                    helpship.findMinMSTAndPreorderTraversal(preorder);
                                                    cout << "0" << endl;
                                                    preorder.push_back(0);
                                                    count=0.0;
                                                    for (int i=0;i<preorder.size()-1;i++){
                                                        count += helpship.calculateNodeDistance(preorder[i],preorder[i+1]);
                                                    }
                                                    cout << "Optimal cost: " << count << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    preorder.clear();
                                                    wait();
                                                    break;
                                                case 3:
                                                    chhh3=3;
                                                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                                    cout << "||--------------------Triangular Approximation Heuristic for small graphs--------------------||" << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    cout << "|| To use this approach in this graph, firstly it´s used the prim´s algorithm to get the prim||" << endl;
                                                    cout << "|| algorithm to get the Minimum Spanning Tree. Only then using Pre-Order Traversal           ||" << endl;
                                                    cout << "|| (left to right) it is calculated the distance.As stadium graph is a fully connected graph,||" << endl;
                                                    cout << "|| it is not necessary to calculate any distance between two nodes, which means that         ||" << endl;
                                                    cout << "|| Haversine distance computation is not used.                                               ||" << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    if(!confirm_read_stad){
                                                        auxfile2.gestor_stadiums(helpsta);
                                                        auxfile2.gestor_travel_stadiums(helpsta);
                                                        confirm_read_stad=true;
                                                    }
                                                    helpsta.findMinMSTAndPreorderTraversal(preorder);
                                                    cout << "0" << endl;
                                                    preorder.push_back(0);
                                                    count=0.0;
                                                    for (int i=0;i<preorder.size()-1;i++){
                                                        count += helpsta.calculateNodeDistance(preorder[i],preorder[i+1]);
                                                    }
                                                    cout << "Optimal cost: " << count << endl;
                                                    cout << "||-------------------------------------------------------------------------------------------||" << endl;
                                                    preorder.clear();
                                                    wait();
                                                    break;
                                                default:
                                                    clearScreen();
                                                    cout << "Invalid option! Try again." << endl;
                                                    wait();
                                                    break;
                                            }
                                        }while(chhh3!=0);
                                }
                            }while(chhh2!=0);


                        default:
                            clearScreen();
                            cout << "Invalid option! Try again." << endl;
                            wait();
                            break;

                    }
                }while (ch1 != 0);
                break;
            case 2:



            default:
                clearScreen();
                cout << "Invalid option! Try again." << endl;
                wait();
                break;
        }

    }while(choice!=0);
    return 0;
}

bool valid_int(const string& s){

    for(auto y : s){
        if(!isdigit(y)){
            return false;
        }
    }
    return true;
}

