#pragma once

namespace restaurant
{
    class DiscountCard
    {
    public:
        virtual ~DiscountCard() = default;
        virtual double apply(double total) const = 0;
    };

    class PercentDiscount : public DiscountCard
    {
    private:
        double factor;

    public:
        explicit PercentDiscount(double percent);
        double apply(double total) const override;
    };
}