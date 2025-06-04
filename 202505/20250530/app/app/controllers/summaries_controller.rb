class SummariesController < ApplicationController
    def index
        response = { score: User.average(:score).to_i }

        render json: response
    end
end
