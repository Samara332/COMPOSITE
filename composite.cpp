//
// Created by adrian on 10/10/20.
//

#include "Patrones/Estructurales/composite.h"
#include <iostream>
bool CNode::IsComposite() {
    return false;
}
string CNode::GetId(){
    return _id;
};

unsigned CLeaf::Operation_A() {
    return 1;
}


void CComposite::Add(shared_ptr<CNode> node){
    _childs.push_back(node);
}
void CComposite::Remove(shared_ptr<CNode> node){
    _childs.remove(node);
}
bool CComposite::IsComposite() {
    return true;
}
unsigned CComposite::Operation_A() {
    unsigned ctd = 0;
    for (auto it : _childs)
        ctd += it->Operation_A();
    return ctd;
}