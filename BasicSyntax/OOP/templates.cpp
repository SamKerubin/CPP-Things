#include <iostream>
#include <list>
#include <algorithm>
#include <optional>

/*
    Templates are something interesting and special,
    it lets you work with one or more type of value, its syntax its like this:

    template <typename T, ...> <- where T can be anything

    You can define a method or even a class as a template, you only need to write
    the class/method down the template statement:

    template...
    class Class <- now this class uses the template
*/

template <typename K, typename V>
class Dictionary
{
public:
    bool set(const K& _K, const V& _V)
    {
        if (_haveKey(_K)) return false;

        keys.push_back(_K);
        values.push_back(_V);

        return true;
    }

    std::optional<V> get(const K& _K) 
    {
        if (!_haveKey(_K)) return std::nullopt;

        int indexOf = _findIndex(_K);
        if (indexOf == -1) return std::nullopt;

        return _getValue(indexOf);
    }

    bool remove(const K& _K)
    {
        if (!_haveKey(_K)) return false;

        int indexOf = _findIndex(_K);
        if (indexOf == -1) return false;

        std::optional<V> value = _getValue(indexOf);

        keys.remove(_K);
        if (value.has_value()) {
            values.remove(value.value());
        }

        return true;
    }

    void print()
    {
        std::cout << "{ ";
        for (auto it_K = keys.begin(), it_V = values.begin(); it_K != keys.end() && it_V != values.end(); ++it_K, ++it_V)
        {
            std::cout << *it_K << ":" << *it_V << " ";
        }
        std::cout << "}" << std::endl;
    }

private:
    std::list<K> keys;
    std::list<V> values;

    bool _haveKey(const K& _K)
    {
        for (const auto& key : keys)
        {
            if (key == _K) return true;
        }
        return false;
    }

    int _findIndex(const K& _K)
    {
        auto it = std::find(keys.begin(), keys.end(), _K);
        if (it != keys.end())
        {
            return std::distance(keys.begin(), it);
        }
        return -1;
    }

    std::optional<V> _getValue(int _Index)
    {
        if (_Index == -1) return std::nullopt;

        auto it = values.begin();
        std::advance(it, _Index);

        return *it;
    }
};

int main()
{
    Dictionary<std::string, int> dict;
    dict.set("A", 1);
    dict.set("B", 2);
    
    if (auto result = dict.get("A"); result) { std::cout << *result << std::endl; } 
    else { std::cout << "null" << std::endl; }

    dict.print();

    return 0;
}