#ifndef RUNNINGAVERAGE_H_
#define RUNNINGAVERAGE_H_
#include <stdint.h>
#include <stddef.h>
#pragma once
//
//    FILE: RunningAverage.h
//  AUTHOR: Rob.Tillaart@gmail.com
// VERSION: 0.3.2
//    DATE: 2016-dec-01
// PURPOSE: Arduino library to calculate the running average by means of a circular buffer
//     URL: https://github.com/RobTillaart/RunningAverage
//
// HISTORY: See RunningAverage.cpp


// #include "Arduino.h"
#include "CircularBuffer.h"


#define RUNNINGAVERAGE_LIB_VERSION    (F("0.3.2"))


template<typename dataType, size_t bufferSize> class RunningAverage
{
public:
//   RunningAverage(const uint8_t size);

    // static constexpr uint8_t capacity = static_cast<uint8_t>(T);

    /**
	 * Disables copy constructor
	 */
	// RunningAverage(const RunningAverage&) = delete;
	// RunningAverage(RunningAverage&&) = delete;


    RunningAverage();
    ~RunningAverage();

    void    clear();
    // void    add(const float value)    { addValue(value); };
    void    addValue(const dataType);
    // void    fillValue(const float, const uint8_t);
    // float   getValue(const uint8_t);

    float   getAverage();      // iterates over all elements.
    float   getFastAverage() const;  // reuses previous calculated values.

    // return statistical characteristics of the running average
    float   getStandardDeviation() const;
    float   getStandardError() const;

    // returns min/max added to the data-set since last clear
    dataType   getMin() const { return _min; };
    dataType   getMax() const { return _max; };

    // returns min/max from the values in the internal buffer
    dataType   getMinInBuffer() const;
    dataType   getMaxInBuffer() const;

    // return true if buffer is full
    bool    bufferIsFull() const { return _array.isFull(); };

    dataType   getElement(uint8_t idx) const;

    size_t getCapacity() const { return _array.capacity(); };
    uint8_t getCount() const { return _array.size(); }


    protected:
    // uint8_t _size;
    // uint8_t _count;
    // uint8_t _index;
    float   _sum;
    // float*  _array;
    dataType   _min;
    dataType   _max;
    
    CircularBuffer<dataType, bufferSize> _array;
};

#include <RunningAverage.tpp>
// -- END OF FILE --t
#endif
