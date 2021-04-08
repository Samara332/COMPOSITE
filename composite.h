//
// Created by adrian on 10/10/20.
//

#ifndef PATRONES_COMPOSITE_H
#define PATRONES_COMPOSITE_H

#include <memory>
#include <list>
#include <string>
using namespace std;

//composite tendrà el control de las lineas de producciòn
class CNode{ //nodo de referencia para la clase composite
protected:
    string _id;
public:
    CNode(string s):_id(s){};
    virtual ~CNode(){}
    virtual void Add(shared_ptr<CNode> node) {}
    virtual void Remove(shared_ptr<CNode> node) {}
    string GetId();
    virtual bool IsComposite();

    virtual unsigned Operation_A() = 0;
};

class CLeaf : public CNode {
public:
    CLeaf(string s):CNode(s){};
    unsigned Operation_A();
};

class CComposite : public CNode {
private:
    list<shared_ptr<CNode>> _childs;
public:
    CComposite(string s):CNode(s){};
    virtual void Add(shared_ptr<CNode> node);
    virtual void Remove(shared_ptr<CNode> node);
    bool IsComposite();

    virtual unsigned Operation_A();
};

#endif //PATRONES_COMPOSITE_H
