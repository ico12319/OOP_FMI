MultiSet::MultiSet(unsigned n, unsigned k) {
    _bucketsCount = (n * k) / _elementsInBucket + 1;
    _buckets = new uint8_t[_bucketsCount]{ 0 };
    _n = n;
    _k = k;
}

void MultiSet::free() {
    delete[] _buckets;
    _bucketsCount = _n = _k = 0;
    _buckets = nullptr;
}

void MultiSet::copyFrom(const MultiSet& other) {
    _buckets = new uint8_t[other._bucketsCount];
    for (size_t i = 0; i < other._bucketsCount; i++)
    {
        _buckets[i] = other._buckets[i];
    }
    _bucketsCount = other._bucketsCount;
    _n = other._n;
    _k = other._k;
}

MultiSet::MultiSet(const MultiSet& other) {
    copyFrom(other);
}
MultiSet& MultiSet::operator=(const MultiSet& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
MultiSet::~MultiSet()
{
    free();
}

//unsigned MultiSet::getBucketNumber(unsigned num) const {
//    unsigned startIndexOfNumber = _k * (num - 1);
//    unsigned result = 0;
//    for (size_t i = _k - 1; i >= 0; i--)
//    {
//        result += _buckets[i] * (1 << (_k - 1 - i));
//    }
//    return result;
//}

unsigned MultiSet::getNumberStartIndex(unsigned num) const
{
    return _k * (num - 1);
}

bool MultiSet::isInOneBuckets(unsigned startIndex) const {
    return startIndex / _elementsInBucket == (startIndex + _k - 1) / _elementsInBucket;
}

unsigned MultiSet::getBucketIndex(unsigned num) const
{
    return num / _elementsInBucket;
}

void MultiSet::add(unsigned num)
{
    if (num > _n) {
        return;
    }
    unsigned startIndexOfNumber = getNumberStartIndex(num);
    unsigned bucketIndex = getBucketIndex(startIndexOfNumber);
    if (isInOneBuckets(startIndexOfNumber)) {
        uint8_t mask = 1 << _elementsInBucket - ((startIndexOfNumber + _k - 1) % _elementsInBucket) - 1;
        std::cout << _buckets[bucketIndex];
        _buckets[bucketIndex] += mask;
        std::cout << _buckets[bucketIndex];
    }
    else {
        unsigned elementsInFirstBucket = _elementsInBucket - (startIndexOfNumber % _elementsInBucket);
        unsigned elementsInSecondBucket = _k - elementsInFirstBucket;
         
        //check in second bucket
        unsigned mask = 0;
        for (size_t i = _elementsInBucket - 1; i >= _elementsInBucket - elementsInSecondBucket; i--)
        {
            mask += (1 << i);
        }
        if (!((_buckets[bucketIndex + 1] & mask) == mask)) {
            _buckets[bucketIndex + 1] += (1 << (_elementsInBucket - elementsInSecondBucket));
            return;
        }

        //check in first bucket
        mask = 0;
        for (size_t i = 0; i < elementsInFirstBucket; i++)
        {
            mask += (1 << i);
        }
        if (!((_buckets[bucketIndex] & mask) == mask)) {
            _buckets[bucketIndex]++;
        }
    }
}
