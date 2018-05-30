//
// Created by MJE on 5/28/2018.
//

#ifndef INC_2D_GAMEENGINE_ENTITYCOMPONENTSYSTEM_H
#define INC_2D_GAMEENGINE_ENTITYCOMPONENTSYSTEM_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;

using ComponentID = std::size_t;

inline ComponentID getNewComponentTypeID() {
    static ComponentID lastID = 0;
    return lastID++;
}

template<typename T>
inline ComponentID getComponentTypeID() noexcept {
    static ComponentID typeID = getNewComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

class Entity;

class Component {
public:
    Entity *entity{};

    virtual void init() {}

    virtual void Update() {}

    virtual void Draw() {}

    virtual ~Component() = default;
};

class Entity {
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray{};
    ComponentBitSet componentBitSet;
public:
    void Update() {
        for (auto &c: components) { c->Update(); }
    }

    void Draw() {
        for (auto &c: components) { c->Draw(); }

    }

    bool isActive() { return active; }

    void destroy() { active = false; }

    template<typename T>
    bool hasComponent() const {
        return componentBitSet[getComponentTypeID<T>()];
    }

    template<typename T, typename ... TArgs>
    T &addComponent(TArgs &&... mArgs) {
        T *c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template<typename T>
    T &getComponent() const {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T *>(ptr);
    }

//    gameobject.getComponenet<PositionComponent().setXpos(25);
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity> > entities;

public:
    void Update() {
        for (auto &e: entities) { e->Update(); }
    }

    void Draw() {
        for (auto &e: entities) { e->Draw(); }
    }

    void refresh() {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                      [](const std::unique_ptr<Entity> &mEntity) { return !mEntity->isActive(); }),
                       std::end(entities));
    }

    Entity &addEntity() {
        auto *e = new Entity();
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};

class EntityComponentSystem {

};


#endif //INC_2D_GAMEENGINE_ENTITYCOMPONENTSYSTEM_H
