/**
 * @file WebResource.hpp
 * @brief Declaration of the WebResource class.
 * This header file defines a searchable web resource object with an url,
 * text content a ranking and a popularity flag derived from the ranking.

*/



#ifndef WEB_RESOURCE_HPP
#define WEB_RESOURCE_HPP

#include <string>


class WebResource {
    private:
        static constexpr int POPULARITY_THRESHOLD = 80;

        std::string url;
        std::string content;
        int ranking;


    public:

        /**
         * @brief Default constructor. Creates a WebResource with default values.
         * 
         */
        WebResource();

        /**
         * @brief Constructs the WebResource object with initial values.
         * 
         * @param[in] url Unique address of the created object
         * @param[in] content textual content of the created object 
         * @param[in] ranking ranking of the created object
         */
        WebResource(const std::string &url, const std::string &content, int ranking);

        /**
         * @brief Returns the content of the object
         * 
         * @return content as a string
         */
        std::string getContent() const;

        /**
         * @brief Sets new content for the object
         * 
         * @param[in] content the new content for the object
         */
        void setContent(const std::string &content);

        /**
         * @brief Return the URL of the object
         * 
         * @return URL as string
         */
        std::string getUrl() const;

        /**
         * @brief Set a new URL for the object
         * 
         * @param[in] url New URL 
         */
        void setUrl(const std::string &url);

        /**
         * @brief Return the ranking of the object
         * 
         * @return Ranking value as int
         */
        int getRanking() const;

        /**
         * @brief Set a new Ranking value for the object
         * 
         * @param[in] ranking New value for Ranking
         */
        void setRanking(int ranking);

        /**
         * @brief Return wether the object is considered popular by it's ranking or not
         * 
         * @return true if considered popular
         * @return false if not
         */
        bool isPopular() const;

};

#endif