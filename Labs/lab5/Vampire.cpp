#include <iostream>
#include "Vampire.h"

using namespace std;

void Vampire::SetValues(string name, int age) {
    m_name = name;
    m_age = age;
}

void Vampire::SuckBlood(string victimName) {
    if (m_fangs)
        cout << "With your fangs out, you feed on " << victimName << endl;
    else {
        cout << m_name << "'s teeth are not out!" << endl;
        cout << victimName << " got away!" << endl;
    }
}

void Vampire::ActivateTeeth() {
    m_fangs = !m_fangs;
}

int Vampire::GetAge() {
    return m_age;
}

string Vampire::GetName() {
    return m_name;
}

void Vampire::Fly() {
    if (m_age > 30)
        cout << m_name << " converts to a bat and flies" << endl;
    else
        cout << m_name << " cannot fly until age 30" << endl;
}
