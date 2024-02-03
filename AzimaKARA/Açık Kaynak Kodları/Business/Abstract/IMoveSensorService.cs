using Entities.Concrete;
using Entities.Dtos;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Abstract
{
    public interface IMoveSensorService
    {
        void Add(MoveSensorDto moveSensorDto);
        Task<MoveSensor> GetEndData();
        Task<List<MoveSensor>> GetMoveSensorAllData();
    }
}
