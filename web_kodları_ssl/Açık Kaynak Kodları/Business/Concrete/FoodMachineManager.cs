using Business.Abstract;
using DataAccess.Abstract;
using Entities.Concrete;
using Entities.Dtos;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class FoodMachineManager : IFoodMachineService
    {
        private readonly IFoodMachineDal _foodMachineDal;

        public FoodMachineManager(IFoodMachineDal foodMachineDal)
        {
            _foodMachineDal = foodMachineDal;
        }

        public void Add(FoodMachineDto foodMachineDto)
        {
            FoodMachine foodMachine = new FoodMachine();
            foodMachine.FillingType = foodMachineDto.FillingType;

            _foodMachineDal.Insert(foodMachine);
        }

        public async Task<FoodMachine> GetEndData()
        {
            var data = await _foodMachineDal.GetList();
            return data.OrderByDescending(x => x.Id).FirstOrDefault();
        }
    }
}
