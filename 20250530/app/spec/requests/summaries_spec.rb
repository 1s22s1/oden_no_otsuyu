require 'rails_helper'

RSpec.describe "Summaries", type: :request do
  describe "GET /index" do
    it "ステータスコードが200であること" do
      get summaries_url, as: :json

      expect(response).to be_successful
    end

    it "レスポンスに、数学と英語の平均値が含まれること" do
      create(:user, score: 60)
      create(:user, score: 70)
      create(:user, score: 80)

      get summaries_url, as: :json

      actual_hash = JSON.parse(response.body)
      expected_hash = { "score" => 70 }

      expect(actual_hash).to eq expected_hash
    end
  end
end
