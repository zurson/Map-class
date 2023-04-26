#ifndef MAP_MAP_H
#define MAP_MAP_H

#include <iostream>
#include <vector>

using namespace std;

template<class Key, class Object> class Map
{
    private:
        class Input
        {
            public:
                Key key;
                Object object;

                Input() {};

                Input(Key key)
                {
                    this->key = key;
                }

                Input(Key key, Object object)
                {
                    this->key = key;
                    this->object = object;
                }

                bool operator==(const Input& x) const
                {
                    return key == x.key;
                }

            };

    protected:
        vector<Input> list;

    public:
        Map() {}

        Map(const Map<Key, Object>& map)
        {
            this->list.clear();

            for(size_t i=0; i<map.list.size(); i++)
                this->list.push_back(map.list[i]);
        }

        bool add(Key key, Object object)
        {
            Input obj(key, object);

            for(size_t i=0; i<this->list.size(); i++)
            {
                if(this->list[i] == obj)
                    return false;
            }

            this->list.push_back(obj);
            return true;
        }

        Object* find(Key key)
        {
            for(size_t i=0; i<this->list.size(); i++)
            {
                if(this->list[i].key == key)
                    return &(this->list[i].object);
            }

            return nullptr;
        }

        Map& operator=(const Map& map)
        {
            this->list.clear();

            for(size_t i=0; i<map.list.size(); i++)
                this->list.push_back(map.list[i]);

            return *this;
        }

        friend ostream& operator<<(ostream& out, const Map& map)
        {
            out << "----------" << endl;

            for(size_t i=0; i<map.list.size(); i++)
                out << map.list[i].key << " : " << map.list[i].object << endl;

            out << "----------" << endl;

            return out;
        }
};

#endif
