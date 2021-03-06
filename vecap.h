#ifndef VECAP_VECAP_H
#define VECAP_VECAP_H

#include <unordered_map>
#include <vector>

namespace container {

template<typename KeyType, typename ValueType>
class Vecap
{
 public:
  using iterator = typename std::vector<ValueType>::iterator;
  using const_iterator = typename std::vector<ValueType>::const_iterator;

  Vecap() = default;

  Vecap(std::initializer_list<std::pair<KeyType, ValueType> > init)
  {
    for (const auto& item : init) {
      push_back(item);
    }
  }

  ValueType& operator[](size_t pos)
  {
    return values_[pos];
  }

  const ValueType& operator[](size_t pos) const
  {
    return values_[pos];
  }

  void push_back(const std::pair<KeyType, ValueType>& item)
  {
    indexes_[item.first] = values_.size();
    values_.push_back(item.second);
  }

  size_t size() const
  {
    return values_.size();
  }

  iterator begin()
  {
    return values_.begin();
  }

  const_iterator begin() const
  {
    return values_.begin();
  }

  iterator end()
  {
    return values_.end();
  }

  const_iterator end() const
  {
    return values_.end();
  }

  iterator find(const KeyType& key)
  {
    auto index = indexes_.find(key);

    if (index == indexes_.end()) {
      return values_.end();
    }

    return values_.begin() + index->second;
  }

  const_iterator find(const KeyType& key) const
  {
    auto index = indexes_.find(key);

    if (index == indexes_.end()) {
      return values_.end();
    }

    return values_.begin() + index->second;
  }

  iterator erase(iterator pos)
  {
    auto index = std::distance(values_.begin(), pos);

    for (auto it = indexes_.begin(); it != indexes_.end();) {
      if (it->second == index) {
        it = indexes_.erase(it);
      } else {
        if (it->second > index) {
          it->second--;
        }
        ++it;
      }
    }

    return values_.erase(pos);
  }

 private:
  std::vector<ValueType> values_;
  std::unordered_map<KeyType, size_t> indexes_;
};

} // namespace container

#endif // VECAP_VECAP_H
