#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <deque>
# include <vector>

class PmergeMe
{
    private:
        std::vector<int> _input;

        struct Element
        {
            std::size_t id;
            int         value;

            Element(std::size_t id, int value);
            bool operator<(const Element& other) const;
        };

        struct Pair
        {
            Element low;
            Element high;

            Pair(const Element& low, const Element& high);
        };

        typedef std::vector<Element>     ElementVector;
        typedef std::vector<Pair>        PairVector;
        typedef std::vector<std::size_t> IndexVector;

        typedef std::deque<Element>      ElementDeque;
        typedef std::deque<Pair>         PairDeque;
        typedef std::deque<std::size_t>  IndexDeque;

        template <typename Elements, typename Indexes>
        struct Chain
        {
            Elements main;
            Elements pending;
            Indexes  bounds;
        };

        template <typename Indexes>
        static Indexes jacobsthalOrder(std::size_t size)
        {
            Indexes order;
            std::size_t previousEnd = 0;
            std::size_t previousJacob = 1;
            std::size_t currentJacob = 3;

            while (previousEnd < size)
            {
                std::size_t end = currentJacob - 2;
                if (end >= size)
                    end = size - 1;
                for (std::size_t i = end; i >= previousEnd; --i)
                {
                    order.push_back(i);
                    if (i == previousEnd)
                        break;
                }
                previousEnd = end + 1;
                std::size_t next = currentJacob + 2 * previousJacob;
                previousJacob = currentJacob;
                currentJacob = next;
            }
            return (order);
        }

        template <typename Elements, typename Pairs>
        static Pairs makePairs(const Elements& input, Elements& main)
        {
            Pairs pairs;

            for (std::size_t i = 0; i + 1 < input.size(); i += 2)
            {
                bool asc = input[i] < input[i + 1];
                pairs.push_back(Pair(input[i + !asc], input[i + asc]));
                main.push_back(pairs.back().high);
            }
            return (pairs);
        }

        template <typename Elements, typename Pairs, typename Indexes>
        static Pairs orderPairs(const Pairs& pairs, const Elements& main)
        {
            Pairs ordered;
            Indexes positions;

            for (std::size_t i = 0; i < pairs.size(); ++i)
            {
                std::size_t id = pairs[i].high.id;
                if (positions.size() <= id)
                    positions.resize(id + 1);
                positions[id] = i;
            }
            for (std::size_t i = 0; i < main.size(); ++i)
                ordered.push_back(pairs[positions[main[i].id]]);
            return (ordered);
        }

        template <typename Elements, typename Pairs, typename Indexes>
        static Chain<Elements, Indexes> makeChain(const Elements& input, const Pairs& pairs)
        {
            Chain<Elements, Indexes> chain;

            chain.main.push_back(pairs[0].low);
			chain.main.push_back(pairs[0].high);
			for (std::size_t i = 1; i < pairs.size(); ++i)
			{
				chain.pending.push_back(pairs[i].low);
				chain.bounds.push_back(chain.main.size());
				chain.main.push_back(pairs[i].high);
			}
            if (input.size() % 2 != 0)
            {
                Element straggler = input.back();
                chain.pending.push_back(straggler);
                chain.bounds.push_back(chain.main.size());
            }
            return (chain);
        }

        template <typename Elements, typename Indexes>
        static void insertPending(Chain<Elements, Indexes>& chain)
        {
            Indexes jacob = jacobsthalOrder<Indexes>(chain.pending.size());

            for (std::size_t i = 0; i < jacob.size(); ++i)
            {
                std::size_t index = jacob[i];
                std::size_t left = 0;
                std::size_t right = chain.bounds[index];

                while (left < right)
                {
                    std::size_t middle = left + (right - left) / 2;
                    if (chain.main[middle] < chain.pending[index])
                        left = middle + 1;
                    else
                        right = middle;
                }
                chain.main.insert(chain.main.begin() + left,chain.pending[index]);
                for (std::size_t j = 0; j < chain.bounds.size(); ++j)
                {
                    if (chain.bounds[j] >= left)
                        ++chain.bounds[j];
                }
            }
        }

        template <typename Elements, typename Pairs, typename Indexes>
        static Elements sort(const Elements& input)
        {
            Elements main;
            Pairs    pairs;

            if (input.size() < 2)
                return (input);
            pairs = makePairs<Elements, Pairs>(input, main);
            main = sort<Elements, Pairs, Indexes>(main);
            pairs = orderPairs<Elements, Pairs, Indexes>(pairs, main);
            Chain<Elements, Indexes> chain = makeChain<Elements, Pairs, Indexes>(input, pairs);
            insertPending<Elements, Indexes>(chain);
            return (chain.main);
        }

        static double processVector(const std::vector<int>& input,
            ElementVector& result);
        static double processDeque(const std::vector<int>& input,
            ElementDeque& result);
        static void validateResults(const ElementVector& vectorResult,
            const ElementDeque& dequeResult);
        static void printBefore(const std::vector<int>& input);
        static void printAfter(const ElementVector& result);
        static void printTime(std::size_t size, const char *container,
            double elapsed);

    public:
        PmergeMe();
        PmergeMe(const std::vector<int>& input);
        PmergeMe(const PmergeMe& toCopy);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& other);
        void run() const;
};

#endif
