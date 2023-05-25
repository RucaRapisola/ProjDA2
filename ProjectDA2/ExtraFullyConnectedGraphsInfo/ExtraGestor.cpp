#include "ExtraGestor.h"
#include <fstream>
#include <sstream>
#include "ExtraGraph.h"

using namespace std;

void ExtraGestor::gestor_25edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_25.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_25edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_25.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_50edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_50.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_50edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_50.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_75edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_75.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_75edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_75.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_100edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_100.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_100edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_100.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_200edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_200.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_200edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_200.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_300edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_300.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_300edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_300.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_400edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_400.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_400edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_400.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_500edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_500.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_500edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_500.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_600edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_600.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_600edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_600.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_700edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_700.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_700edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_700.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_800edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_800.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_800edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_800.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

void ExtraGestor::gestor_900edges(ExtraGraph &aux1){
    bool confirm_repeated1=false;
    bool confirm_repeated2=false;
    ifstream stationf("Extra_Fully_Connected_Graphs/edges_900.csv");
    string line;
    int i=0;
    while(getline(stationf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(stoi(Origem));
        ExtraNodes Nodes2(stoi(Destino));
        if(i==0){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }

        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes1.getID()==itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        for(auto itr=nodes.begin();itr!=nodes.end();itr++){
            if(Nodes2.getID() == itr->second.getID()){
                confirm_repeated1=true;
                break;
            }
        }
        if(confirm_repeated1==false){
            aux1.addVertex(stoi(Origem));
            nodes.insert({stoi(Origem),Nodes1});
        }
        if(confirm_repeated2==false){
            aux1.addVertex(stoi(Destino));
            nodes.insert({stoi(Destino),Nodes2});
        }
        i++;
        confirm_repeated1=false;
        confirm_repeated2=false;
    }
}

void ExtraGestor::gestor_travel_900edges(ExtraGraph &aux1) {
    ifstream travelf("Extra_Fully_Connected_Graphs/edges_900.csv");
    string line;
    while(getline(travelf,line)){
        istringstream iss(line);
        string Origem,Destino,Distancia;
        getline(iss,Origem,',');
        getline(iss,Destino,',');
        getline(iss,Distancia,',');

        ExtraNodes Nodes1(nodes.at(stoi(Origem)));
        ExtraNodes Nodes2(nodes.at(stoi(Destino)));

        aux1.addBidirectionalEdge(Nodes1.getID(),Nodes2.getID(),stof(Distancia));
    }
}

unordered_map<int, ExtraNodes> ExtraGestor::getNodes() const {
    return nodes;
}

unordered_map<int, ExtraNodes> ExtraGestor::getNodes2() const {
    return nodes2;
}
