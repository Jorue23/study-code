#include <string>


class WebResource {
    private:
        std::string url;
        std::string content;
        int importance;


    public:
        WebResource(std::string url, std::string content, int importance)
            : url(url), content(content), importance(importance) {}

        std::string getContent() {
            return this->content;
        }

};

int main() {

    return 0;
}