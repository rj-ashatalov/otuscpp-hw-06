#pragma once

#include <cstdio>
#include <array>
#include <map>

template<typename T, size_t TSize, T TDef>
class Matrix
{
        using matrix_type = Matrix<T, TSize, TDef>;
        using value_type = T;
        using key_type = std::array<size_t, TSize>;

    public:
        template<size_t USize>
        class Proxy
        {
            public:
                Proxy(matrix_type& matrix, key_type&& key)
                        : _matrix(matrix)
                        , _key(std::move(key))
                {
                };

                auto operator[](size_t index)
                {
                    _key[TSize - USize] = index;
                    return Proxy<USize - 1>{_matrix, std::move(_key)};
                };
            private:
                matrix_type& _matrix;
                key_type _key;
        };

        template<>
        class Proxy<0>
        {
            public:
                Proxy(matrix_type& matrix, key_type&& key)
                        : _matrix(matrix)
                        , _key(std::move(key))
                {
                };

                operator value_type()
                {
                    return _matrix.Get(_key);
                }

                auto operator=(const value_type& value)
                {
                    _matrix.Set(_key, value);
                    return *this;
                }

            private:
                matrix_type& _matrix;
                key_type _key;
        };

        Matrix() = default;
        virtual ~Matrix() = default;

        auto operator[](size_t index)
        {
            key_type key;
            key[TSize - TSize] = index;
            return Proxy<TSize - 1>{*this, std::move(key)};
        };

        size_t size()
        {
            return _values.size();
        }

        constexpr auto begin() noexcept
        {
            return _values.begin();
        }

        constexpr auto end() noexcept
        {
            return _values.end();
        }

    private:
        std::map<key_type, value_type> _values;

        value_type Get(const key_type& key)
        {
            auto it = _values.find(key);
            if (it == _values.end())
            {
                return TDef;
            }
            else
            {
                return it->second;
            }
        };

        void Set(const key_type& key, const value_type& value)
        {
            auto it = _values.find(key);
            if (it == _values.end())
            {
                if(value == TDef)
                {
                    return;
                }
                _values.emplace(key, value);
            }
            else if(value == TDef)
            {
                _values.erase(it);
            }
            else
            {
                it->second = value;
            }
        };
};

