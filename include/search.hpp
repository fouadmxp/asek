#pragma once

#include <nlohmann/json.hpp>
#include <set>
#include <string>
#include <unordered_map>

struct SearchResult {
  std::string document;
  double cosineSimilarity;
};

struct CompareSearchResults {
  bool operator()(const SearchResult &a, const SearchResult &b) const {
    return a.cosineSimilarity > b.cosineSimilarity;
  }
};

nlohmann::basic_json<> extract_json_from_file(std::string filePath);

std::multiset<SearchResult, CompareSearchResults>
search_tfidf(const nlohmann::basic_json<> &tfIdfOfAllWords, std::string query,
             size_t numberOfDocuments,
             std::unordered_map<std::string, double> documentsMagnitudes);
