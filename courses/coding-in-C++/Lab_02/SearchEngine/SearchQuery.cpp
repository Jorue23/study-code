/**
 * @file SearchQuery.cpp
 * @brief Implements the SearchQuery class.
 * 
 */

#include "SearchQuery.hpp"

SearchQuery::SearchQuery()
    : query(""), maxResults(MAX_RESULTS_DEFAULT) {}

SearchQuery::SearchQuery(const std::string &query, int maxResults)
    : query(query), maxResults(maxResults) {}

std::string SearchQuery::getQuery() const {
    return this->query;
}

void SearchQuery::setQuery(const std::string &query) {
    this->query = query;
}

int SearchQuery::getMaxResults() const {
    return this->maxResults;
}

void SearchQuery::setMaxResults(int maxResults) {
    this->maxResults = maxResults;
}

bool SearchQuery::isValid() const {
    size_t firstCharacter = query.find_first_not_of(" \t\r\n");
    
    return (firstCharacter != std::string::npos && maxResults > 0);
}
