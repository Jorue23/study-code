/**
 * @file WebResource.cpp
 * @brief This file implements the WebResource class.
*/


#include "WebResource.hpp"

WebResource::WebResource()
    : url(""), content(""), ranking(0) {}

WebResource::WebResource(const std::string &url, const std::string &content, int ranking)
    : url(url), content(content), ranking(ranking) {}

std::string WebResource::getContent() const {
    return this->content;
}

void WebResource::setContent(const std::string &content) {
    this->content = content;
}

std::string WebResource::getUrl() const {
    return this->url;
}

void WebResource::setUrl(const std::string &url) {
    this->url = url;
}

int WebResource::getRanking() const {
    return this->ranking;
}

void WebResource::setRanking(int ranking) {
    this->ranking = ranking;
}

bool WebResource::isPopular() const {
    return this->ranking >= POPULARITY_THRESHOLD;
}
