class FoodRatings {
public:
    unordered_map<string, set<pair<int,string>>> cuisinefoodsRat;
    unordered_map<string,int> foodsRat;
    unordered_map<string,string> cuisfoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < (int)foods.size(); ++i) {
            cuisinefoodsRat[cuisines[i]].insert({-ratings[i], foods[i]});
            foodsRat[foods[i]] = ratings[i];
            cuisfoods[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        int oldRating = foodsRat[food];
        auto &cuisine = cuisfoods[food];
        cuisinefoodsRat[cuisine].erase({-oldRating, food});
        cuisinefoodsRat[cuisine].insert({-newRating, food});
        foodsRat[food] = newRating;
    }

    string highestRated(string cuisine) {
        return cuisinefoodsRat[cuisine].begin()->second;
    }
};