#ifndef PROJECT2GRAPHS_EXTRAGESTOR_H
#define PROJECT2GRAPHS_EXTRAGESTOR_H

#include <unordered_set>
#include <unordered_map>
#include "ExtraNodes.h"
#include "ExtraGraph.h"


class ExtraGestor{
    unordered_map<int, ExtraNodes> nodes;
    unordered_map<int, ExtraNodes> nodes2;

public:
    void gestor_25edges(ExtraGraph &aux);
    void gestor_travel_25edges(ExtraGraph &aux);
    void gestor_50edges(ExtraGraph &aux);
    void gestor_travel_50edges(ExtraGraph &aux);
    void gestor_75edges(ExtraGraph &aux);
    void gestor_travel_75edges(ExtraGraph &aux);
    void gestor_100edges(ExtraGraph &aux);
    void gestor_travel_100edges(ExtraGraph &aux);
    void gestor_200edges(ExtraGraph &aux);
    void gestor_travel_200edges(ExtraGraph &aux);
    void gestor_300edges(ExtraGraph &aux);
    void gestor_travel_300edges(ExtraGraph &aux);
    void gestor_400edges(ExtraGraph &aux);
    void gestor_travel_400edges(ExtraGraph &aux);
    void gestor_500edges(ExtraGraph &aux);
    void gestor_travel_500edges(ExtraGraph &aux);
    void gestor_600edges(ExtraGraph &aux);
    void gestor_travel_600edges(ExtraGraph &aux);
    void gestor_700edges(ExtraGraph &aux);
    void gestor_travel_700edges(ExtraGraph &aux);
    void gestor_800edges(ExtraGraph &aux);
    void gestor_travel_800edges(ExtraGraph &aux);
    void gestor_900edges(ExtraGraph &aux);
    void gestor_travel_900edges(ExtraGraph &aux);

    unordered_map<int, ExtraNodes> getNodes() const;
    unordered_map<int, ExtraNodes> getNodes2() const;

};


#endif //PROJECT2GRAPHS_EXTRAGESTOR_H
