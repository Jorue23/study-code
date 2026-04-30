/**
 * @file SearchQuery.hpp
 * @brief Declaration of the SearchQuery class.
 * This header file defines a query builder object to validate and handle user input.
 * It has query and maximum number of results to be shown to the user.
 */

#ifndef SEARCH_QUERY_HPP
#define SEARCH_QUERY_HPP

#include <string>

class SearchQuery {

    private:

        static constexpr int MAX_RESULTS_DEFAULT = 4;
        std::string query;
        int maxResults;

    public:

        /**
         * @brief Default Constructor for the SearchQuery class.
         * 
         * Creates an empty query with the default amount of maximum results.
         */
        SearchQuery();

        /**
         * @brief Constructs a SearchQuery with initial values.
         * 
         * @param[in] query Text content the user is search for
         * @param max_results Max number of results matching the search to be shown to the user.
         */
        SearchQuery(const std::string &query, int maxResults);

        /**
         * @brief Returns the query of the SearchQuery object.
         * 
         * @return Query as a string
         */
        std::string getQuery() const;

        /**
         * @brief Set a new Query for the SearchQuery object.
         * 
         * @param[in] query the new query for the object.
         */
        void setQuery(const std::string &query);

        /**
         * @brief Returns the maxResults specified by the user.
         * 
         * @return maxResults as int. 
         */
        int getMaxResults() const;

        /**
         * @brief Set a new number of max results for the query.
         * 
         * @param[in] maxResults the new number of max results.
         */
        void setMaxResults(int maxResults);

        /**
         * @brief checks wether the current query is empty and if maxResults is greater then 0.
         * 
         * @return true if query is non empty or made of whitespaces and max results is greater then zero
         * @return false if not
         */
        bool isValid() const;
};


#endif