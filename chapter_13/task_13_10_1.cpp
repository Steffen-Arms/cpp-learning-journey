#include <iostream>

struct WebsiteData
{
    int numberAdsWatched{0};
    double percentageUserClickedAd{0.0};
    double averageEarningPerClick{0.0};
};

std::ostream &operator<<(std::ostream &out, const WebsiteData &w)
{
    return out << "Number of Ads watched: " << w.numberAdsWatched << "\n"
               << "Percentage of users clicked on the ad: "
               << w.percentageUserClickedAd << "\n"
               << "The average earnings per clicked ad: "
               << w.averageEarningPerClick << "\n"
               << "How much I made for the day "
               << w.numberAdsWatched * w.percentageUserClickedAd *
                      w.averageEarningPerClick
               << "\n";
}

WebsiteData getWebsiteData()
{
    WebsiteData tmp{};
    std::cout << "How many ads were watched today? ";
    std::cin >> tmp.numberAdsWatched;
    std::cout << "How many percentage of users clicked on ads? ";
    std::cin >> tmp.percentageUserClickedAd;
    std::cout << "What is the average earning for a ad? ";
    std::cin >> tmp.averageEarningPerClick;
    return tmp;
}

int main()
{
    WebsiteData testData{getWebsiteData()};
    std::cout << testData;
}
