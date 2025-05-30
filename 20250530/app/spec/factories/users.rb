FactoryBot.define do
  factory :user do
    sequence(:name) { |n| "name-#{n}" }
    score { 1 }
  end
end
