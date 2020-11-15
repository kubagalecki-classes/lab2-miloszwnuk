#pragma once

#include "Resource.hpp"

 class ResourceManager
{
    Resource* res;

public:

    ResourceManager()
    {
        res = new Resource;
    }

    ResourceManager(const ResourceManager& rm) // konstruktor kopiujacy
    {
        res = new Resource{ *rm.res };
    }

    ResourceManager(ResourceManager&& rm) // 
    {
        res = nullptr;
        res = rm.res;
        rm.res = nullptr;
    }

    ~ResourceManager()
    {
        delete res;
    }

    double get()
    {
        return res->get();
    }


    ResourceManager operator=(ResourceManager&& rema)
    {
        if (&rema != this) {
            delete res;
            res = rema.res;
            rema.res = nullptr;
        }
        return *this;
    }

    ResourceManager operator=(const ResourceManager& rema) //operator porownana
    {
        if (&rema != this) {
            delete res;
            res = new Resource{ *rema.res };
        }
        return *this;
    }

    
};