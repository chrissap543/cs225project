#include <iostream>


int main() {

Graph graph = new Graph();
buildgraph(graph);



  
}

Graph buildgraph(Graph graph){
    string source;
    string target;

    Node* sourcenode;
    Node* targetnode;

    std::map<string, Node *> mp;


    while(file has next line){
        source = file col 1;
        target = file col 2;

        if (mp.find(source) != mp.end() && mp.find(target) == map.end()){
            auto it = mp.find(source);
            targetnode.name() = target;
            mp.insert({target, targetnode});
            it->second->addNeighbor(targetnode);
        }
        
        else if(mp.find(source) != mp.end() && mp.find(target) != map.end()){
            auto src = mp.find(source);
            auto targ = mp.find(target);

            src->second->addNeighbor(targ->second);

        }
        else if(mp.find(source) == mp.end() && mp.find(target) != map.end()){
            auto it = mp.find(target);
            sourcenode.name() = source;
            mp.insert({source, sourcenode});
            targetnode.addNeighbor(it->second);
        }
        else{
            sourcenode.name() = source;
            targetnode.name() = target;
            mp.insert({source, sourcenode});
            mp.insert({target, targetnode});
            sourcenode.addNeighbor(targetnode);
        }

    }

    

}


