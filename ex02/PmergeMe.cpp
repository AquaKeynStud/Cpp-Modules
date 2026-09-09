#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "PmergeMe.hpp"

using std::deque;
using std::size_t;
using std::vector;

double PmergeMe::processVector(const vector<int>& input,
    ElementVector& result)
{
    ElementVector elements;
    std::clock_t start = std::clock();

    for (size_t i = 0; i < input.size(); ++i)
        elements.push_back(Element(i, input[i]));
    result = sort<ElementVector, PairVector, IndexVector>(elements);
    return (static_cast<double>(std::clock() - start) * 1000.0 / CLOCKS_PER_SEC);
}

double PmergeMe::processDeque(const vector<int>& input,
    ElementDeque& result)
{
    ElementDeque elements;
    std::clock_t start = std::clock();

    for (size_t i = 0; i < input.size(); ++i)
        elements.push_back(Element(i, input[i]));
    result = sort<ElementDeque, PairDeque, IndexDeque>(elements);
    return (static_cast<double>(std::clock() - start) * 1000.0 / CLOCKS_PER_SEC);
}

void PmergeMe::validateResults(const ElementVector& vectorResult,
    const ElementDeque& dequeResult)
{
    if (vectorResult.size() != dequeResult.size())
        throw std::runtime_error("Error: sorting failed");
    for (size_t i = 0; i < vectorResult.size(); ++i)
    {
        if (vectorResult[i].value != dequeResult[i].value)
            throw std::runtime_error("Error: sorting failed");
    }
}

void PmergeMe::printBefore(const vector<int>& input)
{
    std::cout << "Before:";
    for (size_t i = 0; i < input.size(); ++i)
        std::cout << " " << input[i];
    std::cout << "\n";
}

void PmergeMe::printAfter(const ElementVector& result)
{
    std::cout << "After:";
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << " " << result[i].value;
    std::cout << "\n";
}

void PmergeMe::printTime(size_t size, const char *container,
    double elapsed)
{
    std::cout << "Time to process a range of " << size
        << " elements with " << container << " : " << elapsed << " us\n";
}

void PmergeMe::run() const
{
    ElementVector vectorResult;
    ElementDeque dequeResult;

    printBefore(_input);
    double vectorTime = processVector(_input, vectorResult);
    double dequeTime = processDeque(_input, dequeResult);
    validateResults(vectorResult, dequeResult);
    printAfter(vectorResult);
    std::cout << std::fixed << std::setprecision(3);
    printTime(_input.size(), "std::vector", vectorTime);
    printTime(_input.size(), "std::deque", dequeTime);
}

PmergeMe::PmergeMe() : _input(vector<int>()) {}

PmergeMe::PmergeMe(const vector<int>& input) : _input(input) {}

PmergeMe::PmergeMe(const PmergeMe& toCopy) : _input(toCopy._input) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
        _input = other._input;
    return (*this);
}

PmergeMe::Element::Element(size_t elementId, int elementValue) : id(elementId), value(elementValue) {}

bool PmergeMe::Element::operator<(const Element& other) const
{
    return (value < other.value);
}

PmergeMe::Pair::Pair(const Element& lower, const Element& higher) : low(lower), high(higher) {}
