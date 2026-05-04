/**
 * @file SearchEngine.hpp
 * @brief Declaration of the SearchEngine class.
 * 
 */

#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <string>

#include "WebResource.hpp"
#include "SearchQuery.hpp"

class SearchEngine {
    private:
        static constexpr int MAX_WEB_RESOURCES = 70;
        static int totalQueries;

        WebResource webResources[MAX_WEB_RESOURCES];
        static int totalWebResources;

        SearchQuery currentQuerry;

        WebResource currentSearchResult[MAX_WEB_RESOURCES];
        static int validSearchCount;



    public:
};

#endif