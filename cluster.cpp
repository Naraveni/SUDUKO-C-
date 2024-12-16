#include "cluster.hpp"

//constructor
Cluster::Cluster(Square* sqr[9], ClusterT cltype, int n): type((ClusterType[static_cast<int>(cltype)]).c_str()), n(n){
    for(int m=0;m<n;m++){
        sq[m] = sqr[m];
        sq[m]->addCluster(this);
    }
}

//printing all the squares inside the cluster 
ostream& Cluster::print(ostream& out) const{
    out<< type << '\n';
    for(int m = 0;m<n;m++){
    out << *sq[m];
    }
    return out << '\n';
}

//manipulating the possibility of a square clusters after a value is marked by user
void Cluster::shoop(char val){
    int value =  val-'0';
    for(int m = 0;m<n;m++){
        sq[m]->turnOff(value);
    }
}