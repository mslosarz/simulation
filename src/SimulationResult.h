/*
 * SimulationResult.h
 *
 *  Created on: 9 gru 2013
 */

#ifndef SIMULATIONRESULT_H_
#define SIMULATIONRESULT_H_

class SimulationResult {
public:
	SimulationResult() :
			beginClientsBalance(0), finalClientsBalance(0), shopIncome(0), leftPriceOfProducts(0) {
	}
	virtual ~SimulationResult() {
	}

	float getBeginClientsBalance() const {
		return beginClientsBalance;
	}

	void addBeginClientsBalance(float clientBalance) {
		this->beginClientsBalance += clientBalance;
	}

	float getFinalClientsBalance() const {
		return finalClientsBalance;
	}

	void setFinalClientsBanalce(float balance){
		this->finalClientsBalance = balance;
	}

	void addFinalClientsBalance(float clientBalance) {
		this->finalClientsBalance += clientBalance;
	}

	float getLeftPriceOfProducts() const {
		return leftPriceOfProducts;
	}

	void setLeftPriceOfProducts(float productPrice) {
		this->leftPriceOfProducts = productPrice;
	}

	float getBeginPriceOfProducts() const {
		return beginPriceOfProducts;
	}

	void setBeginPriceOfProducts(float beginPriceOfProducts) {
		this->beginPriceOfProducts = beginPriceOfProducts;
	}

	float getShopIncome() const {
		return shopIncome;
	}

	void setShopIncome(float shopIncome) {
		this->shopIncome = shopIncome;
	}

private:
	float beginClientsBalance;
	float finalClientsBalance;
	float shopIncome;
	float beginPriceOfProducts;
	float leftPriceOfProducts;
};

#endif /* SIMULATIONRESULT_H_ */
